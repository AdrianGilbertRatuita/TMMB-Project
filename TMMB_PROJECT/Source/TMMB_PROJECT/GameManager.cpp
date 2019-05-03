// Fill out your copyright notice in the Description page of Project Settings.

#include "GameManager.h"

#include "BaseCaster.h"
#include "Engine/Engine.h"

#include "Runtime/Engine/Classes/GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/GameViewportClient.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectIterator.h"

// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{

	Super::BeginPlay();

	//if (GetWorld())
	//{

	//	GetWorld()->GetGameViewport()->SetDisableSplitscreenOverride(!bSplitScreen);
	//	GetWorld()->GetGameViewport()->UpdateActiveSplitscreenType();

	//}	

}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetWorld())
	{

		//for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
		//{

		//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Controller: %i"), Iterator.GetIndex()));

		//}

	}

}


void AGameManager::AssignControl(ABaseCaster * PawnCaller)
{

	if (GetWorld())
	{

		FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator() + PawnCaller->PlayerNumber - 1;

		APawn * DefaultPawnReference = Iterator->Get()->GetPawn();

		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Player %i: %i, %s"), PawnCaller->PlayerNumber, Iterator.GetIndex(), *Iterator->Get()->GetName()));

		Iterator->Get()->Possess(PawnCaller);

		if (DefaultPawnReference) GetWorld()->DestroyActor(DefaultPawnReference);

	}

}



