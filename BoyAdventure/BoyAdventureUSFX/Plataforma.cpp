// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APlataforma::APlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AllMesh"));
	RootComponent = MeshPlataforma;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MeshAsset.Succeeded()) {
		MeshPlataforma->SetStaticMesh(MeshAsset.Object);
		MeshPlataforma->SetRelativeScale3D(FVector(2.0f, 2.0f, 0.3f));
	}


}

void APlataforma::Moverse(float DeltaTime)
{
    if (!bPuedeMoverse) return; // solo se movera si esta activado

    // Si es la primera vez que se activa se guarda la posición inicial
    if (!bMovimientoIniciado)
    {
        PosicionInicial = GetActorLocation();
        bMovimientoIniciado = true;
    }

    // Aumentamos el tiempo
    Tiempo += DeltaTime;

    // Movimiento simple arriba y abajo
    float MovimientoX = FMath::Sin(Tiempo * Velocidad) * Distancia; //postada: Estudiar mas sobre esto

    // Aplicamos el movimiento
    FVector NuevaPosicion = PosicionInicial;
    NuevaPosicion.X += MovimientoX;
    SetActorLocation(NuevaPosicion);
}

// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Moverse(DeltaTime);
}

