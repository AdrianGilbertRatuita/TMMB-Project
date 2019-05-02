	// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseCaster.generated.h"

UCLASS(abstract)
class TMMB_PROJECT_API ABaseCaster : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseCaster();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Caster Control - Character Data", meta = (AllowPrivateAccess = "true"))
		FKey ShootKey;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Caster Control - Character Data", meta = (AllowPrivateAccess = "true"))
		class AGameManager * GameManager;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Caster Control - Character Data", meta = (AllowPrivateAccess = "true"))
		bool bCanShoot;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Caster Control - Character Data", meta = (AllowPrivateAccess = "true"))
		int KillCount = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Caster Control - Character Data", meta = (AllowPrivateAccess = "true"))
		int DeathCount = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Caster Control - Character Data", meta = (AllowPrivateAccess = "true"))
		int32 PlayerNumber;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Caster Control - Character Data", meta = (AllowPrivateAccess = "true"))
		FName StaffSocket = "StaffSocket";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Caster Control - Character Data", meta = (AllowPrivateAccess = "true"))
		float CurrentMana = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Caster Control - Character Data", meta = (AllowPrivateAccess = "true"))
		float MaximumMana = 100;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Caster Control - Character Data", meta = (AllowPrivateAccess = "true"))
		float MovementSpeed = 500;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Caster Control - Character Data", meta = (AllowPrivateAccess = "true"))
		float CurrentDirection;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Caster Control - Character Data", meta = (AllowPrivateAccess = "true"))
		float MovementDirection;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Caster Control - Components", meta = (AllowPrivateAccess = "true"))
		class UCapsuleComponent * CapsuleComponent;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Caster Control - Components", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent * StaffMeshComponent;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Caster Control - Components", meta = (AllowPrivateAccess = "true"))
		class USkeletalMeshComponent * SkeletalMeshComponent;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Caster Control - Components", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent * CameraComponent;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Caster Control - Components", meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent * SpringArmComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Pure Virtual Spellcast for future implementation
	virtual void SpellCast() PURE_VIRTUAL(ABaseCaster::SpellCast, ;);

	//virtual void ApplyMovement();
	//virtual void ApplyRotation();
	//
	//virtual void SpellCast();

	// Timer for Cooldown
	FTimerHandle CooldownTimer;

	//
	float LeftMovementX = 0;
	float LeftMovementY = 0;

	//
	float RightMovementX = 0;
	float RightMovementY = 0;

	//
	virtual void LeftXMove(float AxisValue);
	virtual void LeftYMove(float AxisValue);

	//
	void CooldownOff();

	// For future implementation
	void RightXMove(float AxisValue);
	void RightYMove(float AxisValue);

	//virtual void ApplyMovement();
	virtual void ApplyRotation();

};
