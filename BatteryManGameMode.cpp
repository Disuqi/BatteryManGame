// Copyright Epic Games, Inc. All Rights Reserved.

#include "BatteryManGameMode.h"
#include "BatteryManCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Actor.h"


ABatteryManGameMode::ABatteryManGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ABatteryManGameMode::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABatteryManGameMode::SpawnPlayerRecharge, FMath::RandRange(2, 5), true);
	FTimerHandle SecondUnusedHandle;
	GetWorldTimerManager().SetTimer(SecondUnusedHandle, this, &ABatteryManGameMode::SpawnSpecialPlayerRecharge, FMath::RandRange(5, 10), true);
}

void ABatteryManGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABatteryManGameMode::SpawnPlayerRecharge()
{
	FVector SpawnPosition = getRandomPosition();
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	GetWorld()->SpawnActor(PlayerRecharge, &SpawnPosition, &SpawnRotation);
}

void ABatteryManGameMode::SpawnSpecialPlayerRecharge()
{
	FVector SpawnPosition = getRandomPosition();
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	GetWorld()->SpawnActor(SpecialPlayerRecharge, &SpawnPosition, &SpawnRotation);
}

FVector ABatteryManGameMode::getRandomPosition()
{
	float RandX = FMath::RandRange(Spawn_X_Min, Spawn_X_Max);
	float RandY = FMath::RandRange(Spawn_Y_Min, Spawn_Y_Max);

	FVector SpawnPosition = FVector(RandX, RandY, Spawn_Z);
	return SpawnPosition;
}
