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
	bCanShoot = true;
	/*UWorld *WRLD = GetWorld();

	FVector location = GetActorLocation();
	FRotator rotation = GetActorRotation();*/

	//WRLD->SpawnActor(ActorToSpawn, &location, &rotation);

}

void AElementalist::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);	

	InputComponent->BindKey(ShootKey, EInputEvent::IE_Pressed, this, &AElementalist::SpellCast);
	InputComponent->BindKey(ChangeSpellKey, EInputEvent::IE_Pressed, this, &AElementalist::ChangeSpell);
	InputComponent->BindKey(EKeys::SpaceBar, EInputEvent::IE_Pressed, this, &AElementalist::SpellCast);
	InputComponent->BindAxisKey(EKeys::Gamepad_LeftX, this, &AElementalist::LeftXMove);
	InputComponent->BindAxisKey(EKeys::Gamepad_LeftY, this, &AElementalist::LeftYMove);


}

void AElementalist::ChangeSpell()
{
	uint8 OffsetSpell = (uint8)CurrentSpell;
	OffsetSpell++;

	if (OffsetSpell > 2)
	{
		OffsetSpell = 0;
	}

	CurrentSpell = (ElementalistSpell)OffsetSpell;
}


void AElementalist::SpellCast()
{

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("PLAYER: %i"), PlayerNumber));
	bShooting = false;
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("PLAYER: %i"), PlayerNumber));

	switch (CurrentSpell)
	{

		case ElementalistSpell::FIREBALL:
		{
			if (CurrentMana >= 10 && bCanShoot)
			{
				FireSpawn_Implementation();
				bShooting = true;
				bCanShoot = false;
				CurrentMana -= 10;

				GetWorld()->GetTimerManager().SetTimer(CooldownTimer, this, &AElementalist::CooldownOff, 0.5f, false);

			}
			break;
		}
		case ElementalistSpell::ICESHARD:
		{
			if (CurrentMana >= 5 && bCanShoot)
			{
				IceSpawn_Implementation();
				bShooting = true;
				bCanShoot = false;
				CurrentMana -= 5;

				GetWorld()->GetTimerManager().SetTimer(CooldownTimer, this, &AElementalist::CooldownOff, 0.5f, false);

			}
	
			break;
		}
		case ElementalistSpell::LIGHTNING:
		{
			if (CurrentMana >= 15 && bCanShoot)
			{
				LightningSpawn_Implementation();
				bShooting = true;
				bCanShoot = false;
				CurrentMana -= 15;

				GetWorld()->GetTimerManager().SetTimer(CooldownTimer, this, &AElementalist::CooldownOff, 0.5f, false);

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

