// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoPinchos.h"

AObstaculoPinchos::AObstaculoPinchos()
{
	PrimaryActorTick.bCanEverTick = true;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
    if (MeshAsset.Succeeded()) {
        AllMesh->SetStaticMesh(MeshAsset.Object);
        //MeshObstaculo->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
    }

    static ConstructorHelpers::FObjectFinder<UMaterialInterface>MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Steel.M_Metal_Steel'"));

    if (MaterialAsset.Succeeded()) {
        AllMesh->SetMaterial(0, MaterialAsset.Object);
    }
}

void AObstaculoPinchos::Activar(float DeltaTime) {
    // Si es la primera vez que se activa se guarda la posición inicial
    if (!bMovimientoIniciado)
    {
        PosicionInicial = GetActorLocation();
        bMovimientoIniciado = true;
    }

    // Aumentamos el tiempo
    Tiempo += DeltaTime;

    // Movimiento simple arriba y abajo
    float MovimientoZ = FMath::Sin(Tiempo * Velocidad) * Altura; //postada: Estudiar mas sobre esto

    // Aplicamos el movimiento
    FVector NuevaPosicion = PosicionInicial;
    NuevaPosicion.Z += MovimientoZ;
    SetActorLocation(NuevaPosicion);
}

void AObstaculoPinchos::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    Activar(DeltaTime);
}