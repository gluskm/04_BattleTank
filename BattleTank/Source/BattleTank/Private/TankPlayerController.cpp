// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayController not possesing tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing %s"), *(ControlledTank->GetName()));
	}
	//UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"));
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

	FVector OutHitLocation; //Out Parameter
	if(GetSightRayHitLocation(OutHitLocation)) //Has sid effect - its line trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *OutHitLocation.ToString());
	}
	
		//TODO Tell controlled tank to aim at this point
}

//Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Find the crosshair poistion
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	
	//de-project the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation,LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
	}

	//Line trace along the look direction and see what we hit(up to the range)
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // To be discarded
	FVector WorldDirection;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	
}