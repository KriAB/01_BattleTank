// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "TankTurret.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: C++ construct"), *TankName)
}

void ATank::BeginPlay()
{
	Super::BeginPlay(); // Needed for BP begin play
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("DONKEY: %2 C++ Begin Play"), *TankName)
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (!ensure(ProjectileBlueprint)) { return; }
	if (!ensure(Barrel)) { return; }
	if (Barrel && bIsReloaded) 
	{  

	// Spawn a projectile at the socket location on the barrow
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,		//Hva som spawnes
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
		);

	Projectile->LaunchProjectile(LaunchSpeed);
	LastFireTime = FPlatformTime::Seconds();
	}
}