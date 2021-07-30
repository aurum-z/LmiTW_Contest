// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

// Подключение новых объектов
//#include "BP_DoorSlider.uasset"
#include "Misc/FileHelper.h"
#include "Engine.h"
#include "Engine/Blueprint.h"
#include "GeneratorFunctionLibrary.generated.h"



#define BP_Door ABP_DoorSlider
//MyOtherActor* otheractorname;

/**
 * 
 */

 /*
USTRUCT(BlueprintType)
struct FPlayerStats
{
	GENERATED_BODY()
		// Use UPROPERTY() to decorate member variables as they allow for easier integration with network replication as well as potential garbage collection processing
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DisplayInfo)
		float x1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DisplayInfo)
		float y;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DisplayInfo)
		float w1;
};
*/



UCLASS()
class LMITW_API UGeneratorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		// Объявим функции
		//UFUNCTION(BlueprintPure, Category = "Custom", meta = (KeyWords = "ProceduralGenerator"))
		UFUNCTION(Category = "Custom", meta = (KeyWords = "ProceduralGenerator"))
		//FPlayerStats Neuron_Multi_Input_1(int epochs, int learnSpeed);
		uint32 checkNodesIssues(int learnSpeed);

		//UFUNCTION(BlueprintCallable, Category = "Inventory")
		//ABP_DoorSlider* getDoors();
	public:
		UFUNCTION(BlueprintCallable, Category = "TextFile", meta = (KeyWords = "SaveText"))
			static bool customSaveStringToFile(FString InputText, FString FileNameB);

		UFUNCTION(BlueprintPure, Category = "TextFile", meta = (KeyWords = "LoadText"))
			static bool customConvertFileToString(FString FileNameA, FString& SaveTextA);
	
};
