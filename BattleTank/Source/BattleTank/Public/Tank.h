// NGankedd

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Fire();

private:
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UTankBarrel* Barrel = nullptr; // TODO Remove dis bitch.

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBluePrint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeSeconds = 3;

	double LastFireTime = 0;
	
};