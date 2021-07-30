// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayActors/MasterPickup.h"

// Sets default values
AMasterPickup::AMasterPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMasterPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMasterPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

