// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "BaseDestructibleSpell.h"
#include "Components/PrimitiveComponent.h"
#include "Elementalist.h"
#include "LightingDestructibleSpell.generated.h"

/**
 * 
 */
UCLASS()
class TMMB_PROJECT_API ALightingDestructibleSpell : public ABaseDestructibleSpell
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void OnComponentHit2(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	void OnComponentFracture(FVector HitPoint, FVector HitDirection);

};
