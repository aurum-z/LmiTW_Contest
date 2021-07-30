// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayActors/MasterSwitcherStatusSetter.h"

// Sets default values
AMasterSwitcherStatusSetter::AMasterSwitcherStatusSetter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMasterSwitcherStatusSetter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMasterSwitcherStatusSetter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


//void AMasterDoorStatusSetter::CheckDataTableOnMistakes(FS_DoorRangeStatus* structIn) {

//}

