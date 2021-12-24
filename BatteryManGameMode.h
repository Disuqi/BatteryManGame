// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BatteryManGameMode.generated.h"

UCLASS(minimalapi)
class ABatteryManGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<APawn> PlayerRecharge;

	UPROPERTY(EditAnywhere)
		TSubclassOf<APawn> SpecialPlayerRecharge;

	float Spawn_Z = 500.0f;
	UPROPERTY(EditAnywhere)
		float Spawn_X_Min;

	UPROPERTY(EditAnywhere)
		float Spawn_X_Max;
	
	UPROPERTY(EditAnywhere)
		float Spawn_Y_Min;
	UPROPERTY(EditAnywhere)
		float Spawn_Y_Max;

	void SpawnPlayerRecharge();

	void SpawnSpecialPlayerRecharge();

	FVector getRandomPosition();

public:
	ABatteryManGameMode();
};



