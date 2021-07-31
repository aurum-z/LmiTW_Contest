// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LMBaseCharacter.generated.h"

#define CHANNEL_COMBAT UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_EngineTraceChannel3)

UCLASS()
class LMITW_API ALMBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALMBaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter|Combat")
	void SphereTraceForTarget(FHitResult& OutHit, const FVector& Start, const FVector& End, float Radius, const TArray<AActor*>& ActorsToIgnore);

};


