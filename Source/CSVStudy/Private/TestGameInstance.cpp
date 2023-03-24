// Fill out your copyright notice in the Description page of Project Settings.


#include "TestGameInstance.h"

UTestGameInstance::UTestGameInstance()
{
	UE_LOG(LogTemp, Error, TEXT("@@@@@@@@@@@@@@@@@@@@@"));
	FString str = TEXT("ab김c현d");
	TArray<FString> arr;
	for (int32 i = 0; i < str.Len(); i++)
	{
		arr.Add(str.Mid(i, 1));
		
	}
}

void UTestGameInstance::Init()
{
	Super::Init();

	number = 111;

	
}