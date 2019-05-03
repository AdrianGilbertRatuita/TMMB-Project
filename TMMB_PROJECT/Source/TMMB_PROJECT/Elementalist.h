// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "BaseCaster.h"
#include "Components/PrimitiveComponent.h"
#include "Elementalist.generated.h"

UENUM(BlueprintType)
enum class ElementalistSpell : uint8
{

	FIREBALL UMETA(DisplayName = "Fire"),
	ICESHARD UMETA(DisplayName = "Ice"),
	LIGHTNING UMETA(DisplayName = "Lightning")

};

/**
 * 
 */
UCLASS()
class TMMB_PROJECT_API AElementalist : public ABaseCaster
{
	GENERATED_BODY()
		
public:

	AElementalist();

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Elementalist Control - Spell Spawning", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class ABaseDestructibleSpell> FireBP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Elementalist Control - Spell Spawning", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class ABaseDestructibleSpell> IceBP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Elementalist Control - Spell Spawning", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class ABaseDestructibleSpell> LightningBallBP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Elementalist Control - Spell Spawning", meta = (AllowPrivateAccess = "true"))
		ElementalistSpell CurrentSpell;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Elementalist Control - Spell Spawning", meta = (AllowPrivateAccess = "true"))
		void FireSpawn();
		void FireSpawn_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Elementalist Control - Spell Spawning", meta = (AllowPrivateAccess = "true"))
		void IceSpawn();
		void IceSpawn_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Elementalist Control - Spell Spawning", meta = (AllowPrivateAccess = "true"))
		void LightningSpawn();
		void LightningSpawn_Implementation();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void SpellCast() override;

	//virtual void LeftXMove(float AxisValue) override;
	//virtual void LeftYMove(float AxisValue) override;

};
