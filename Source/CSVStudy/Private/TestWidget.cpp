// Fill out your copyright notice in the Description page of Project Settings.


#include "TestWidget.h"
#include <Components/Button.h>

void UTestWidget::NativeConstruct()
{
	btn = Cast<UButton>(GetWidgetFromName(TEXT("Button_68")));
	
	//UTestButton t;
	UTestButton* testButton = NewObject<UTestButton>();
	testButton->Init(100, this);
	
	btn->OnClicked.AddDynamic(testButton, &UTestButton::OnClick);

	btn = Cast<UButton>(GetWidgetFromName(TEXT("Button")));

	//UTestButton t;
	testButton = NewObject<UTestButton>();
	testButton->Init(200, this);

	btn->OnClicked.AddDynamic(testButton, &UTestButton::OnClick);
}

void UTestWidget::OnButtonClicked(bool bIsChecked, int32 Param1, float Param2)
{
	// ...
}

void UTestWidget::OnClick(int32 index)
{
	UE_LOG(LogTemp, Warning, TEXT("Click : %d"), index);
}

