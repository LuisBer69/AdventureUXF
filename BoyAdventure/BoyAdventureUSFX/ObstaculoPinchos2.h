// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstaculoPinchos.h"
#include "ObstaculoPinchos2.generated.h"

/**
 * 
 */
UCLASS()
class BOYADVENTUREUSFX_API AObstaculoPinchos2 : public AObstaculoPinchos
{
	GENERATED_BODY()

public:
	AObstaculoPinchos2();

    virtual void Tick(float DeltaTime) override;
    virtual void Activar(float DeltaTime) override;

    // Tiempos de cada movimiento
    float TiempoMovimientoY = 20.0f; // Segundos moviendose en Y;
    float TiempoMovimientoX = 8.0f; // Segundos oscilando en X;
    float TiempoActual = 0.0f;
    bool bMoviendoEnY = true;
    float DistanciaX = 100.0f; // Amplitud de oscilacion en X
    FVector PosicionBase;
    bool bMovimientoIniciado = false;
	
};
