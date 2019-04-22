// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseDestructibleSpell.generated.h"

UCLASS()
class TMMB_PROJECT_API ABaseDestructibleSpell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseDestructibleSpell();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Spell Destructible - Components", meta = (AllowPrivateAccess = "true"))
		class UDestructibleComponent * DestructibleComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
