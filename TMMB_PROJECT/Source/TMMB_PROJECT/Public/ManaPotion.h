// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ManaPotion.generated.h"

UCLASS()
class TMMB_PROJECT_API AManaPotion : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AManaPotion();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Potion - Property", meta = (AllowPrivateAccess = "true"))
		float Mana;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Potion - Property", meta = (AllowPrivateAccess = "true"))
		float RotationSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Potion - Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent * StaticMeshComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
