// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties

	void AimAt(FVector OutHitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	ATank();

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000; // TODO find sensible default
};