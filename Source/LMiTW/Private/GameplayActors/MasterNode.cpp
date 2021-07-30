// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayActors/MasterNode.h"

// Sets default values
AMasterNode::AMasterNode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMasterNode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMasterNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

