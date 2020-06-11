// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const; 

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	/// Start the tank moving the barrel so that a shot 
	/// would hit it where the cross-hair 
	/// intersects the world
	void AimTowardsCrosshair();


	// Return an out parameter, true if hit location
	bool GetSightRayHitLocation(FVector& OutHitLocation) const; 

};