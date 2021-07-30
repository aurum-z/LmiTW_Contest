// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayActors/MasterDoor.h"

// Sets default values
AMasterDoor::AMasterDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMasterDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMasterDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

