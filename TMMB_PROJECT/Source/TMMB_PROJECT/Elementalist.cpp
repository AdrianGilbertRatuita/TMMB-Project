// Fill out your copyright notice in the Description page of Project Settings.

#include "Elementalist.h"

#include "Engine.h"
#include "BaseDestructibleSpell.h"

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

	InputComponent->BindKey(ShootKey, EInputEvent::IE_Pressed, this, &AElementalist::SpellCast);
	InputComponent->BindKey(EKeys::SpaceBar, EInputEvent::IE_Pressed, this, &AElementalist::SpellCast);
	InputComponent->BindAxisKey(EKeys::Gamepad_LeftX, this, &AElementalist::LeftXMove);
	InputComponent->BindAxisKey(EKeys::Gamepad_LeftY, this, &AElementalist::LeftYMove);

}

void AElementalist::SpellCast()
{

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("PLAYER: %i"), PlayerNumber));
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

void AElementalist::FireSpawn_Implementation()
{

}

void AElementalist::IceSpawn_Implementation()
{

}

void AElementalist::LightningSpawn_Implementation()
{

}

