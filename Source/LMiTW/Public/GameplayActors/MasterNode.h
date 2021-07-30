// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"

#include "MasterNode.generated.h"


USTRUCT(BlueprintType)
struct FnodeMainStruct {
	GENERATED_USTRUCT_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "NodeAttributes")
		//UPROPERTY( VisibleAnywhere,/* BlueprintReadWrite,*/ Category = Node)
		//int32 doors;
		//TSubclassOf<class ABP_Node> nodes;
		//UClass* anyActorTest;
		//TSubclassOf<ABP_Node> doors;
		AActor* doio;

};






UCLASS()
class LMITW_API AMasterNode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMasterNode();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Node)
	FnodeMainStruct struct_1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
