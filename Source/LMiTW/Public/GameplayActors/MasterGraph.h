// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "SGraphNode.h"
#include "Math/UnrealMathUtility.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MasterGraph.generated.h"
#define border 888


///// we need this sheet?
USTRUCT(BlueprintType)
struct F2DArray {
	GENERATED_USTRUCT_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite/*, Category = "DisplayInfo"*/)
		TArray<bool> edgeXY;

};
////

USTRUCT(BlueprintType)
struct FPathesInfo {
	GENERATED_USTRUCT_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite/*, Category = "DisplayInfo"*/)
	int offsetOfStartIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite/*, Category = "DisplayInfo"*/)
	int amountOfRooms = 0;

};

//add category "GameDesign"
UENUM(BlueprintType)
enum class EFilterOfPathes : uint8
{
	None = 0				UMETA(DisplayName = "Path filter off. Only random"),
	ByAmountOfRooms	= 1		UMETA(DisplayName = "By amount of rooms in path"),
	ByLengthPercent	= 2		UMETA(DisplayName = "By path length statistic in percent"),

};


UCLASS()
class LMITW_API AMasterGraph : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMasterGraph();
	UPROPERTY(EditAnywhere, BlueprintReadWrite/*, Category = Node*/)
	TArray<F2DArray> adjacencyMatrix;
	UPROPERTY(EditAnywhere, BlueprintReadWrite/*, Category = Node*/)
	TArray<bool> Graph2dMatrix;
	// BELOW COME TO PRIVATE
	UPROPERTY(EditAnywhere, BlueprintReadWrite/*, Category = Node*/)
	TArray<int> list; // LIFO

	UPROPERTY(EditAnywhere, BlueprintReadWrite/*, Category = Node*/)
	TArray<int> branchPointsID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite/*, Category = Node*/)
	TArray<bool> usedVertex; // vertex where we were in Current Path

	// END BUTTON COME TO PRIVATE


	UFUNCTION(BlueprintCallable)
	void setNewNodeConnectToMatrix(TArray<bool> arr, int nodeID1, int nodeID2, TArray<bool>& arrOut);
	UFUNCTION(BlueprintCallable)
	bool pathesSearcher(TArray<bool> arrVertex, int startVertexID, int targetVertexID, TArray<int>& arrPathes888);
	UFUNCTION(BlueprintCallable)
	void pathesGameDesignFilter(TArray<int> pathesArr, EFilterOfPathes Enum, int inAmountOfRooms, int inLengthPercent, TArray<int>& FilteredPath);
	
	TArray<int> filterNeighborsByUsedStatusAndPushToList(TArray<int> nID, int currentIndex);
	TArray<int> searchNeighborsID(TArray<bool> arrVertex, int arrHeigh, int currentIndex);
	TArray<int> duplicateLastPathWithoutBorder(TArray<int> pathID, int pathPointerOffset);
	






protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
