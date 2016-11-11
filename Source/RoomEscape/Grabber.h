// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROOMESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	

	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	// How far the player can reach in cm
	float Reach = 100.0f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	//raycast and grab whats in reach
	void Grab();

	//Release held object
	void Release();

	//find attached physics component
	void FindPhysicsHandleComponent();

	// setup attached input component
	void SetupInputComponent();
	
	//return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	// returns current start of reach line
	FVector GetReachLineStart();

	// returns current end of reach line
	FVector GetReachLineEnd();
	
};
