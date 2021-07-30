// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayActors/MasterGraph.h"

// Sets default values
AMasterGraph::AMasterGraph()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMasterGraph::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMasterGraph::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMasterGraph::setNewNodeConnectToMatrix(TArray<bool> arr, int nodeID1, int nodeID2, TArray<bool> &arrOut) {

	int arrHeigh = sqrt(arr.Num());
	int row = nodeID1;
	int col = nodeID2;

	arr[arrHeigh * row + col] = true;
	arr[arrHeigh * col + row] = true;
	arrOut = arr;
}




// To debug this function watch "pathID, list, nID, usedVertex, branchPointsID"
bool AMasterGraph::pathesSearcher(TArray<bool> arrVertex, int startVertexID, int targetVertexID, TArray<int>& arrPathes888) {

	int arrHeigh = sqrt(arrVertex.Num());

	if (arrHeigh < 2) {
		//print ERR; Graph cant be less then 2
		GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, "BP_Graph: pathesSearcher function. ERR. Graph array matrix less then 2x2");
		return false;
	}
	else if (startVertexID >= arrHeigh) {
		GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, "BP_Graph: pathesSearcher function. ERR. Start vertex ID bigger then array heigh");
		return false;
	}
	else if (startVertexID == targetVertexID){
		GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, "BP_Graph: pathesSearcher function. ERR. StartVertexID cant be qual targetVertexID ");
		return false;
	}
	
	TArray<int> nID; // neighbors ID
	TArray<int> pathID;
	int pathPointerOffset = 0;
	

	// Generate Used Vertex array
	for (int i = 0; i < arrHeigh; i++) {  
		usedVertex.Add(0);
	}
	

	list.Push(startVertexID); // 0 by default
	usedVertex[0] = true;

	start:
	while (list.Num() != 0) {

		int currentIndex = list[0];
		pathID.Push(currentIndex); // Push last Vertex 
		usedVertex[currentIndex] = 1;
		list.RemoveAt(0, 1, true);


		if (pathID.Last() == targetVertexID) { // if we find target Vertex
			pathID.Push(border); // 
			int acum;
			if (list.Num() > 0) { // If we have vertex where to come and continue search pathes	
				int n = 0;
				acum = pathID.Num();

				//// Create part of future path - START
					pathID = duplicateLastPathWithoutBorder(pathID, pathPointerOffset);
					// remove excess pathID`es
					while (pathID.Last() != branchPointsID[0]) {
						usedVertex[pathID.Last()] = 0;				//write free vertex
						pathID.RemoveAt(pathID.Num() - 1, 1, true);
						n++;
					}
				//// Create part of future path - END
				
				pathPointerOffset = acum;
				branchPointsID.RemoveAt(0, 1, true);
				goto start;
			}
			else {
				break; // Exit from while
			}
		}
		else {
			nID = searchNeighborsID(arrVertex, arrHeigh, currentIndex);
			nID = filterNeighborsByUsedStatusAndPushToList(nID, currentIndex);
		}
		//

		if (nID.Num() == 0) { // if we hit a dead end 
			if (list.Num() > 0) {
				int n = 0;

				// Delete path elements
				while (pathID.Last() != branchPointsID[0]) {
					usedVertex[pathID.Last()] = 0;				// write free vertex
					pathID.RemoveAt(pathID.Num() - 1, 1, true);
					n++;
				}

				branchPointsID.RemoveAt(0, 1, true);
				goto start;
			}
			else {
				break; // Exit from while
			}
		}	
	}
	arrPathes888 = pathID;
	return true;
}







// Search Neighbors ID`es for current Vertex ID
TArray<int> AMasterGraph::searchNeighborsID(TArray<bool> arrVertex, int arrHeigh, int currentIndex) {
	TArray<int> nID;
	for (int i = 0; i < arrHeigh; i++) {
		if (arrVertex[arrHeigh * currentIndex + i] == 1) {
			nID.Insert(i, 0);
		}
	}
	return nID;
}


TArray<int> AMasterGraph::filterNeighborsByUsedStatusAndPushToList(TArray<int> nID, int currentIndex) {
	TArray<int> nIDout;
	short counter = 0;
	for (int nIndex = 0; nIndex < nID.Num(); nIndex++) {
		if (usedVertex[nID[nIndex]] == 0) {
			list.Insert(nID[nIndex], 0);
			nIDout.Push(nID[nIndex]);
			if (counter > 0) {// if whe got branch
				branchPointsID.Insert(currentIndex, 0);
			}
			counter++;
		}
	}
	return nIDout;
}


TArray<int> AMasterGraph::duplicateLastPathWithoutBorder(TArray<int> pathID, int pathPointerOffset){
	short n = 0;
	short ID;
	while(pathID[pathPointerOffset + n] != border){
		ID = pathID[pathPointerOffset + n];
		pathID.Push(ID);
		n++;
	}
	return pathID;
}


void AMasterGraph::pathesGameDesignFilter(TArray<int> pathesArr, EFilterOfPathes Enum, int inAmountOfRooms, int inLengthPercent, TArray<int>& FilteredPath) {
	TArray<FPathesInfo> infoArr;
	FPathesInfo info;
	unsigned int offset = 0;
	for (int i = 0; i < pathesArr.Num(); i++) {
		if (pathesArr[i] == border) {
			info.amountOfRooms = i - offset; // - 1 for jump "border"
			info.offsetOfStartIndex = offset;
			infoArr.Add(info);
			offset = i + 1;						  // + 1 for jump "border"
		}
	}
	unsigned int choosedArrIndex = 9999;
	int weight = 0;
	switch (Enum) {
		case EFilterOfPathes::None: 
			choosedArrIndex = FMath::RandRange(0, infoArr.Num() - 1);
			break;

		case EFilterOfPathes::ByAmountOfRooms:
			while (choosedArrIndex == 9999) {
				for (int i = 0; i < infoArr.Num(); i++) {
					if (inAmountOfRooms + weight == infoArr[i].amountOfRooms) {
						choosedArrIndex = i;
						goto exit;
					}
					if (weight != 0) {
						if (inAmountOfRooms - weight == infoArr[i].amountOfRooms) {
							choosedArrIndex = i;
							goto exit;
						}
					}
				}			
				weight++;			
			}
			exit:
			break;

		case EFilterOfPathes::ByLengthPercent:
			// sort array in ascending order 
				int k;
				for (int i = 0; i < infoArr.Num(); i++) {
					for (k = 0; k + i < infoArr.Num(); k++) {
						if (infoArr[i].amountOfRooms > infoArr[k + i].amountOfRooms){
							FPathesInfo infoBuff = infoArr[i];
							infoArr[i] = infoArr[k + i];
							infoArr[k + i] = infoBuff;
						} 		
					}
				}
			// 
			choosedArrIndex = (float(infoArr.Num() - 1) / 100) * inLengthPercent;
			break;
	}
	unsigned int ID;
	for (int i = 0; i < infoArr[choosedArrIndex].amountOfRooms; i++) {
		ID = pathesArr[i + infoArr[choosedArrIndex].offsetOfStartIndex];
		FilteredPath.Push(ID);
	}
	//GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::White, "BP_Graph: None Filter "); 
	
}











/*void AMasterGraph::AddElement(TArray<bool> arr, int row, int col)
{
	int arrSquareSize = sqrt(sizeof(arr));

	for (int counter1 = 0; counter1 < arrSquareSize; counter1++)
	{
		for (int counter2 = 0; counter2 < arrSquareSize; counter2++)
		{
			//arr[counter1 * row + counter2] = false;
			arr.Add(false);
			
		}
	}








	if (row == 999) {
		arr.Add(false);
	}
	else if (col == 999) {
		arr.Add(false);
	}
	int arrSize = sqrt(sizeof(arr));
	//array[width * row + col] = value;
	//array[width * col + row] = value;

}*/

//void AMasterGraph::CustomAddElement(F2DArray ArrToModif, bool newElement) {
//	ArrToModif.edgeXY.Add(newElement);
//}

