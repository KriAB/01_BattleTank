// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"
//Foreward Declaration:
class ATank;
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

private:
	

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override; //Virtual betyr at barn av klassen kan override

	//Start the tank moving the barrel so that a shout would hit where
	//the crosshair intersects the world
	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	

	
	UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
		float CrosshairYLocation = 0.3333;

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;
};
