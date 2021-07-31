// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LMBaseCharacter.h"

#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ALMBaseCharacter::ALMBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALMBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALMBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALMBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ALMBaseCharacter::SphereTraceForTarget(FHitResult& OutHit, const FVector& Start, const FVector& End, float Radius, const TArray<AActor*>& ActorsToIgnore)
{
	UKismetSystemLibrary::SphereTraceSingle(this, Start, End, Radius, CHANNEL_COMBAT, true, ActorsToIgnore, EDrawDebugTrace::None, OutHit, true);
}

