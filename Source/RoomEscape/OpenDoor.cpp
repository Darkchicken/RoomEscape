// Fill out your copyright notice in the Description page of Project Settings.

#include "RoomEscape.h"
#include "OpenDoor.h"


#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	// Find the owning actor
	Owner = GetOwner();
	if (!PressurePlate)
	{
		//log that the owner is missing an input component 
		UE_LOG(LogTemp, Error, TEXT("%s mising Pressure Plate"), *GetOwner()->GetName());
	}
	
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Poll the Trigger Volume
	if (GetTotalMassOfActorsOnPlate() > 30.0f) // TODO make into a parameter
	{
		OpenDoor();
		//Set door open time
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	//check if its time to close the door
	if (GetWorld()->GetTimeSeconds()- LastDoorOpenTime > DoorCloseDelay)
	{
		CloseDoor();
	}
	
	
}

float UOpenDoor::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.0f;

	// find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!PressurePlate) { return TotalMass; }
	PressurePlate -> GetOverlappingActors(OUT OverlappingActors);
	
	// Iterate through them adding their masses
	for (const auto& Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName());
	}
	return TotalMass;
}

void UOpenDoor::OpenDoor()
{
	
	// Create a rotator and Set the door rotation
	//Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));

	// Broadcasts the OnOpenRequest Event
	OnOpenRequest.Broadcast();
}

void UOpenDoor::CloseDoor()
{
	//Create a Rotator and Set the door rotation
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}


