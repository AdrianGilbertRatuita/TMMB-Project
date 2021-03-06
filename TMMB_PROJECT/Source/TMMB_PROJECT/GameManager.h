// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameManager.generated.h"

UCLASS()
class TMMB_PROJECT_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameManager();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Manager - Game Settings", meta = (AllowPrivateAccess = "true"))
		int NumberOfPlayers;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Manager - Game Settings", meta = (AllowPrivateAccess = "true"))
		bool bSplitScreen = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AssignControl(class ABaseCaster * PawnCaller);

};
