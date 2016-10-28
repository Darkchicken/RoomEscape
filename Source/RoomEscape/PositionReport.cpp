// Fill out your copyright notice in the Description page of Project Settings.

#include "RoomEscape.h"
#include "PositionReport.h"


// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();
	//stores object name as an FString
	FString ObjectName = GetOwner()->GetName();
	//stores position of object as an FString
	FString ObjectPos = GetOwner()-> GetTransform().GetLocation().ToString();//"X = something, Y = something else";
	//pass object name and position to log
	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"),*ObjectName, *ObjectPos);
	
}


// Called every frame
void UPositionReport::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

