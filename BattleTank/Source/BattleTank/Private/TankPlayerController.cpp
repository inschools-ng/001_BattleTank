// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay(); 

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation;	// Out Parameter
	if (GetSightRayHitLocation(OutHitLocation)) // Will ray-trace 
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *OutHitLocation.ToString());
		// TODO Tell controlled tank to aim at this point 
	}
}

// Get a world location of line-trace through cross-hair, true if hits landscape 

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//	find the cross-hair position 
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto Screenlocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *Screenlocation.ToString());


	//	De-project the screen position of the cross-hair to a world direction
	//	Line-trace along that look direction, and see what we hit (up to max range)
	OutHitLocation = FVector(1.0);
	return true;
}
