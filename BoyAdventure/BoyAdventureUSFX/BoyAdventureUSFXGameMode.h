// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BoyAdventureUSFXGameMode.generated.h"

class AObstaculoPinchos;

UCLASS(minimalapi)
class ABoyAdventureUSFXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABoyAdventureUSFXGameMode();

public:
	virtual void BeginPlay() override;
public:
	void SpawnActor(FVector Locacion, FRotator Rotacion );

public:
	void CrearPlataformas();
};



