// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoPinchos2.h"

AObstaculoPinchos2::AObstaculoPinchos2()
{
    TiempoMovimientoY = 20.0f; // Segundos moviéndose en Y
    TiempoMovimientoX = 8.0f; // Segundos oscilando en X
    TiempoActual = 0.0f;
    bMoviendoEnY = true;
    DistanciaX = 100.0f; // Amplitud de oscilación en X
    bMovimientoIniciado = false;
}

void AObstaculoPinchos2::Activar(float DeltaTime)
{
    if (!bMovimientoIniciado)
    {
        PosicionBase = GetActorLocation();
        bMovimientoIniciado = true;
    }

    TiempoActual += DeltaTime;

    if (bMoviendoEnY)
    {
        // Movimiento vertical como el padre
        Tiempo += DeltaTime;
        float MovimientoZ = FMath::Sin(Tiempo * Velocidad) * Altura;
        FVector NuevaPos = PosicionBase;
        NuevaPos.Z += MovimientoZ;
        SetActorLocation(NuevaPos);

        if (TiempoActual >= TiempoMovimientoY)
        {
            TiempoActual = 0.0f;
            bMoviendoEnY = false;
            Tiempo = 0.0f; // Reinicia el tiempo para la oscilacion en X
        }
    }
    else
    {
        // Oscilación en X, sin avanzar la posicion base
        Tiempo += DeltaTime;
        float MovimientoX = FMath::Sin(Tiempo * Velocidad) * DistanciaX;
        FVector NuevaPos = PosicionBase;
        NuevaPos.X += MovimientoX;
        SetActorLocation(NuevaPos);

        if (TiempoActual >= TiempoMovimientoX)
        {
            TiempoActual = 0.0f;
            bMoviendoEnY = true;
            Tiempo = 0.0f; // Reinicia el tiempo para la oscilacion en Y
        }
    }
}

void AObstaculoPinchos2::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Activar(DeltaTime);
}