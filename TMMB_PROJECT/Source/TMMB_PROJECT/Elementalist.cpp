// Fill out your copyright notice in the Description page of Project Settings.

#include "Elementalist.h"

#include "Engine.h"

AElementalist::AElementalist()
{

}

void AElementalist::BeginPlay()
{

	Super::BeginPlay();	

}

void AElementalist::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);	

	InputComponent->BindAxisKey(EKeys::Gamepad_LeftX, this, &AElementalist::LeftXMove);
	InputComponent->BindAxisKey(EKeys::Gamepad_LeftY, this, &AElementalist::LeftYMove);

	InputComponent->BindAxisKey(EKeys::Gamepad_RightX, this, &AElementalist::RightXMove);
	InputComponent->BindAxisKey(EKeys::Gamepad_RightY, this, &AElementalist::RightYMove);

}

void AElementalist::SpellCast()
{

	switch (CurrentSpell)
	{

		case ElementalistSpell::FIREBALL:
		{

			break;
		}
		case ElementalistSpell::ICESHARD:
		{

			break;
		}
		case ElementalistSpell::LIGHTNING:
		{

			break;
		}

	}

}

void AElementalist::LeftXMove(float AxisValue)
{

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("%f"), AxisValue));

	Super::LeftXMove(AxisValue);

}

void AElementalist::LeftYMove(float AxisValue)
{

	Super::LeftYMove(AxisValue);

}


void AElementalist::FireSpawn_Implementation()
{
}

void AElementalist::IceSpawn_Implementation()
{
}

void AElementalist::LightningSpawn_Implementation()
{
}

