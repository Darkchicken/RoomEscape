// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROOMESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void OpenDoor();
	void CloseDoor();

	UPROPERTY(BlueprintAssignable)
	FOnOpenRequest OnOpenRequest;

private:
	
	UPROPERTY(EditAnywhere) //< property for angle, shows in inspector
	float OpenAngle = -90.0f;//<angle that the door will open

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr; //< Pressure plate to open door

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.8f;

	float LastDoorOpenTime;

	// The owning door
	AActor* Owner = nullptr; //< The owning door

	// returns total mass in kg
	float GetTotalMassOfActorsOnPlate();
		
	
};
