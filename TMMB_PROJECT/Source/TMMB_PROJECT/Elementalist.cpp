// Fill out your copyright notice in the Description page of Project Settings.

#include "Elementalist.h"
//#include "Engine.h"
#include "BaseDestructibleSpell.h"

AElementalist::AElementalist()
{

}

void AElementalist::BeginPlay()
{

	Super::BeginPlay();	
	/*UWorld *WRLD = GetWorld();

	FVector location = GetActorLocation();
	FRotator rotation = GetActorRotation();*/

	//WRLD->SpawnActor(ActorToSpawn, &location, &rotation);

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


	switch (CurrentSpell)
	{

		case ElementalistSpell::FIREBALL:
		{
			if (CurrentMana >= 10)
			{
				FireSpawn_Implementation();
				//CurrentMana -= 10;
			}
			break;
		}
		case ElementalistSpell::ICESHARD:
		{
			if (CurrentMana >= 10)
			{
				IceSpawn_Implementation();
				//CurrentMana -= 10;
			}

			
			break;
		}
		case ElementalistSpell::LIGHTNING:
		{
			if (CurrentMana >= 10)
			{
				LightningSpawn_Implementation();
				//CurrentMana -= 10;
			}
			break;
		}

	}

}

void AElementalist::FireSpawn_Implementation()
{

	

	UWorld *WRLD = GetWorld();

	FVector location = GetActorLocation();

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("FORWARD: %s"), *GetActorForwardVector().ToString()));

	location += GetActorForwardVector() * 150;

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("WHERE: %s"), *location.ToString()));

	FRotator rotation = GetActorRotation();

	WRLD->SpawnActor(FireToSpawn, &location, &rotation);
}

void AElementalist::IceSpawn_Implementation()
{
	UWorld *WRLD = GetWorld();

	FVector location = GetActorLocation();

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("FORWARD: %s"), *GetActorForwardVector().ToString()));

	location += GetActorForwardVector() * 150;

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("WHERE: %s"), *location.ToString()));

	FRotator rotation = GetActorRotation();

	WRLD->SpawnActor(IceToSpawn, &location, &rotation);
}

void AElementalist::LightningSpawn_Implementation()
{
	UWorld *WRLD = GetWorld();

	FVector location = GetActorLocation();

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("FORWARD: %s"), *GetActorForwardVector().ToString()));

	location += GetActorForwardVector() * 150;

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("WHERE: %s"), *location.ToString()));

	FRotator rotation = GetActorRotation();

	WRLD->SpawnActor(LightingToSpawn, &location, &rotation);
}

