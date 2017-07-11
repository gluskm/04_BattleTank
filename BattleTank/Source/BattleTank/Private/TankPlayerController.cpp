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

	//Get world location if linetrace through crosshai
	//If hits the landscape
		//Tell controlled tank to aim at this point
}

