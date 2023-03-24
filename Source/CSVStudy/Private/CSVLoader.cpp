// Fill out your copyright notice in the Description page of Project Settings.


#include "CSVLoader.h"
#include <Kismet/KismetSystemLibrary.h>


// Sets default values
ACSVLoader::ACSVLoader()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//ConstructorHelpers::FObjectFinder<UDataTable> tempData(TEXT("DataTable'/Game/DB_UserData.DB_UserData'"));
	//if (tempData.Succeeded())
	//{
	//	UDataTable* data = tempData.Object;
	//	//���� (���� ����)
	//	TArray<FName> rowNames = data->GetRowNames();
	//	for (int32 i = 0; i < rowNames.Num(); i++)
	//	{
	//		//�� �࿡���� �����͸� ��������
	//		FUserInfo* userInfo = data->FindRow<FUserInfo>(rowNames[i], TEXT(""));
	//		//�츮�� ���� Array �־�����
	//		userData.Add(*userInfo);
	//	}
	//}

}

// Called when the game starts or when spawned
void ACSVLoader::BeginPlay()
{
	Super::BeginPlay();

	UDataTable* data = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/DB_UserData.DB_UserData'"));
	//���� (���� ����)
	TArray<FName> rowNames = data->GetRowNames();
	for (int32 i = 0; i < rowNames.Num(); i++)
	{
		//�� �࿡���� �����͸� ��������
		FUserInfo* userInfo = data->FindRow<FUserInfo>(rowNames[i], TEXT(""));
		//�츮�� ���� Array �־�����
		userData.Add(*userInfo);
	}



	//FString path = FPaths::Combine(FPaths::ProjectDir(), TEXT("CSVData/UserData.csv"));
	//userData = Parse<FUserInfo>(path, FUserInfo::StaticStruct());// Parse(path); //FUserInfo

	/*path = FPaths::Combine(FPaths::ProjectDir(), TEXT("CSVData/ProductData.csv"));
	productData = Parse<FProductInfo>(path, FProductInfo::StaticStruct());*/

}

// Called every frame
void ACSVLoader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}


TArray<FUserInfo> ACSVLoader::Parse(FString path)
{
	//���� �����͸� ���� Array
	TArray<FUserInfo> data;

	//path �� �ִ� ������ �о����
	FString fileContent;
	if (FFileHelper::LoadFileToString(fileContent, *path))
	{
		//UE_LOG(LogTemp, Error, TEXT("%s"), *fileContent);
		//��(����) ������
		TArray<FString> rows;
		fileContent.ParseIntoArrayLines(rows);

		//�����̸� ������
		TArray<FString> variableName;
		rows[0].ParseIntoArray(variableName, TEXT(","));

		//��(data) ������
		for (int32 i = 1; i < rows.Num(); i++)
		{
			TArray<FString> values;
			rows[i].ParseIntoArray(values, TEXT(","));

			//�ϳ��� �����͸� ����ü ����
			FUserInfo info;
			info.name = values[0];
			info.age = FCString::Atoi(*values[1]);
			info.isWoman = values[2].ToBool();
			info.height = FCString::Atof(*values[3]);
			info.mbti = values[4];

			data.Add(info);
		}
	}

	return data;
}



template<typename T>
TArray<T> ACSVLoader::Parse(FString path, UScriptStruct* pScriptStuct)
{
	//���� �����͸� ���� Array
	TArray<T> data;

	//path �� �ִ� ������ �о����
	FString fileContent;
	if (FFileHelper::LoadFileToString(fileContent, *path))
	{
		//UE_LOG(LogTemp, Error, TEXT("%s"), *fileContent);
		//��(����) ������
		TArray<FString> rows;
		fileContent.ParseIntoArrayLines(rows);

		//�����̸� ������
		TArray<FString> variableName;
		rows[0].ParseIntoArray(variableName, TEXT(","));

		//��(data) ������
		for (int32 i = 1; i < rows.Num(); i++)
		{
			TArray<FString> values;
			rows[i].ParseIntoArray(values, TEXT(","));

			//�ϳ��� �����͸� ����ü ����
			T info;
			for (int32 j = 0; j < variableName.Num(); j++)
			{
				//�ش� ���� �̸����� �Ǿ��ִ� ������ ������ ��������
				FProperty* pro = pScriptStuct->FindPropertyByName(*variableName[j]);

				if (pro->IsA<FStrProperty>())
				{
					FString* valuePtr = pro->ContainerPtrToValuePtr<FString>(&info);
					*valuePtr = values[j];
				}

				else if (pro->IsA<FIntProperty>())
				{
					int32* valuePtr = pro->ContainerPtrToValuePtr<int32>(&info);
					*valuePtr = FCString::Atoi(*values[j]);
				}

				else if (pro->IsA<FBoolProperty>())
				{
					bool* valuePtr = pro->ContainerPtrToValuePtr<bool>(&info);
					*valuePtr = values[j].ToBool();
				}

				else if (pro->IsA<FFloatProperty>())
				{
					float* valuePtr = pro->ContainerPtrToValuePtr<float>(&info);
					*valuePtr = FCString::Atof(*values[j]);
				}
			}

			data.Add(info);
		}
	}

	return data;
}