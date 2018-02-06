// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


	

	// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));

}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Playercontroller not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Playercontroller possessing: %s"), *(ControlledTank->GetName()));

	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	//Get world location if  linetrace through crosshair
	//If it hits the landscape
		//Tell controlled tank to aim at this point. 
}
