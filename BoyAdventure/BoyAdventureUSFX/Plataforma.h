// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plataforma.generated.h"

UCLASS()
class BOYADVENTUREUSFX_API APlataforma : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlataforma();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void Moverse(float DeltaTime);

	// Variables para el movimiento
	float Distancia = 50.0f;
	float Velocidad = 2.0f;
	FVector PosicionInicial;
	float Tiempo = 0.0f;
	bool bMovimientoIniciado = false;

	class UStaticMeshComponent* MeshPlataforma;

public:
	bool bPuedeMoverse;
};
