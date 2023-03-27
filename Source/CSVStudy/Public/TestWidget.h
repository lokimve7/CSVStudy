// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TestWidget.generated.h"



/**
 * 
 */
UCLASS()
class CSVSTUDY_API UTestWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UPROPERTY()
	class UButton* btn;

	UFUNCTION()
	void OnButtonClicked(bool bIsChecked, int32 Param1, float Param2);

	void OnClick(int32 index);
};

UCLASS()
class UTestButton : public UObject
{
	GENERATED_BODY()
public:
	UTestButton() {}

	int32 index;

	UPROPERTY()
	UTestWidget* target;

	void Init(int32 n, UTestWidget* t)
	{
		index = n;
		target = t;
	}

	UFUNCTION()
	void OnClick()
	{
		target->OnClick(index);
	}
};
