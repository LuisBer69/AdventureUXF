// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstaculo.h"

// Sets default values
AObstaculo::AObstaculo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//RAIZ MESH
	AllMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AllMesh"));
	RootComponent = AllMesh;

}

// Called when the game starts or when spawned
void AObstaculo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstaculo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//TAREA LAB02
void AObstaculo::Activar(float DeltaTime) {
	//IMPLEMENTAR EN LAS CLASES HIJAS
}

