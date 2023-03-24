// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Engine/DataTable.h>
#include "CSVLoader.generated.h"

USTRUCT(BlueprintType)
struct FUserInfo : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FString name = "";

	UPROPERTY(EditAnywhere)
	int32 age = 0;

	UPROPERTY(EditAnywhere)
	bool isWoman = false;

	UPROPERTY(EditAnywhere)
	float height = 0;

	UPROPERTY(EditAnywhere)
	FString mbti = "";
};


USTRUCT(BlueprintType)
struct FProductInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere)
		FString kname;

	UPROPERTY(VisibleAnywhere)
		int32 price;

	UPROPERTY(VisibleAnywhere)
		bool sale;

	UPROPERTY(VisibleAnywhere)
		float weight;

};

UCLASS()
class CSVSTUDY_API ACSVLoader : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACSVLoader();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<FUserInfo> Parse(FString path);

	template<typename T>
	TArray<T> Parse(FString path, UScriptStruct* pScriptStuct);

	UPROPERTY(EditAnywhere)
	TArray<FUserInfo> userData;

	UPROPERTY(EditAnywhere)
	TArray<FProductInfo> productData;
};
