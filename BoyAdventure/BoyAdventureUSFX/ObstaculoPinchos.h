// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "ObstaculoPinchos.generated.h"

/**
 * 
 */
UCLASS()
class BOYADVENTUREUSFX_API AObstaculoPinchos : public AObstaculo
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AObstaculoPinchos();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//TAREA LAB02
public:
	virtual void Activar(float DeltaTime) override;

	// Variables para el movimiento
	float Altura = 50.0f;
	float Velocidad = 2.0f;
	FVector PosicionInicial;
	float Tiempo = 0.0f;
	bool bMovimientoIniciado = false;
};
