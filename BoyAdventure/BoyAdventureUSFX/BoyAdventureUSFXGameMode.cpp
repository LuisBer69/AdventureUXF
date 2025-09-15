// Copyright Epic Games, Inc. All Rights Reserved.

#include "BoyAdventureUSFXGameMode.h"
#include "BoyAdventureUSFXCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "ObstaculoPinchos.h"
#include "Plataforma.h"

ABoyAdventureUSFXGameMode::ABoyAdventureUSFXGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void  ABoyAdventureUSFXGameMode::BeginPlay() {
	Super::BeginPlay();

	/*Spawn normal
	FVector Posicion(0.0f, 0.0f, 150.0f);
	FRotator Rotacion = FRotator::ZeroRotator;
	SpawnActor(Posicion, Rotacion);
	*/

	/*Spawn linea
	FVector PosicionBase(0.0f, 0.0f, 150.0f);
	FRotator Rotacion = FRotator::ZeroRotator;
	float Espaciado = 100.0f; //Distancia entre cada actor

	int Cantidad = 10;//Numero de Actores

	for (int i = 0; i < Cantidad; i++) {
		FVector Posicion = PosicionBase + FVector(i * Espaciado, 0.0f, 0.0f);
		SpawnActor(Posicion, Rotacion);
	}*/

	/*Spwan matriz
	FVector PosicionBase(0.0f, 0.0f, 150.0f);
	FRotator Rotacion = FRotator::ZeroRotator;
	float EspaciadoX = 100.0f; // Espaciado entre columnas
	float EspaciadoY = 100.0f; // Espaciado entre filas

	int Filas = 5;
	int Columnas = 5;

	for (int fila = 0; fila < Filas; ++fila) {
		for (int col = 0; col < Columnas; ++col) {
			FVector Posicion = PosicionBase + FVector(fila * EspaciadoX, col * EspaciadoY, 0.0f);
			SpawnActor(Posicion, Rotacion);
		}
	}*/

	/*Spawn usando contenedore y logica para mover solo ciertos actores
	FVector PosicionBase(0.0f, 0.0f, 150.0f);
	FRotator Rotacion = FRotator::ZeroRotator;
	float Espaciado = 100.0f; //Distancia entre cada actor

	int Cantidad = 10;//Numero de Actores

	// Array para guardar los actores

	for (int i = 0; i < Cantidad; i++) {
		FVector Posicion = PosicionBase + FVector(i * Espaciado, 0.0f, 0.0f);

		// Spawneamos el actor
		AObstaculoPinchos* NuevoActor = SpawnActor(Posicion, Rotacion);

		// Por defecto, todos los actores NO se mueven
		NuevoActor->bActivarMovimiento; // Variable para activar el movimiento
		NuevoActor->bActivarMovimiento = false;

		SpawnPinchos.Add(NuevoActor);
	}*/

	CrearPlataformas();
}

void ABoyAdventureUSFXGameMode::CrearPlataformas()
{
	UWorld* Mundo = GetWorld();
	if (!Mundo) return;

	TArray<APlataforma*> MisPlataformas;

	for (int Piso = 0; Piso < 2; Piso++)
	{
		for (int i = 0; i < 5; i++)
		{
			FVector Posicion = FVector(i * -300.0f, 0.0f, Piso * 200.0f + 100.0f);

			APlataforma* Plataforma = Mundo->SpawnActor<APlataforma>(
				APlataforma::StaticClass(),
				Posicion,
				FRotator::ZeroRotator
			);

			if (Plataforma)
			{
				// Fórmula simple para intercalar
				// Piso 0: pares=true, impares=false
				// Piso 1: pares=false, impares=true
				Plataforma->bPuedeMoverse = (i % 2 == Piso % 2);

				MisPlataformas.Add(Plataforma);
			}
		}
	}
}

void ABoyAdventureUSFXGameMode::SpawnActor(FVector Locacion, FRotator Rotacion) {
	UWorld* Mundo = GetWorld();
	if (Mundo) {
		Mundo->SpawnActor<AObstaculoPinchos>(AObstaculoPinchos::StaticClass(), Locacion, Rotacion);
	}
}