// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionLibraries/GeneratorFunctionLibrary.h"


uint32 UGeneratorFunctionLibrary::checkNodesIssues(int learnSpeed)
{
	uint32 x = 0;
	return x;
}

bool UGeneratorFunctionLibrary::customSaveStringToFile(FString InputText, FString FileNameB)
{
	FText Err1;
	Err1.FromString("function customSaveStringToFile: ERROR. Not valid file name");

	if (FFileHelper::IsFilenameValidForSaving(FileNameB, Err1)) {
		return FFileHelper::SaveStringToFile((InputText + "\r\n"), *(FPaths::ProjectDir() + FileNameB), FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
	}
	else {
		return false;
	}
}

bool UGeneratorFunctionLibrary::customConvertFileToString(FString FileNameA, FString& SaveTextA)
{
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::ProjectDir() + FileNameA));
}