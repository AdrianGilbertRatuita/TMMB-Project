// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "BaseDestructibleSpell.h"
#include "Components/PrimitiveComponent.h"
#include "Elementalist.h"
#include "IceDestructibleSpell.generated.h"

/**
 * 
 */
UCLASS()
class TMMB_PROJECT_API AIceDestructibleSpell : public ABaseDestructibleSpell
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
		void OnComponentHit(class UPrimitiveComponent* OverlappedHit, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};