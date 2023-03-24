// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TestGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CSVSTUDY_API UTestGameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public:
	UTestGameInstance();

	virtual void Init() override;

	UPROPERTY(BlueprintReadWrite)
	int32 number = 0;
};
