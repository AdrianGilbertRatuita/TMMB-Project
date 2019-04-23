// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseDestructibleSpell.h"
#include "DestructibleComponent.h"


// Sets default values
ABaseDestructibleSpell::ABaseDestructibleSpell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DestructibleComponent = CreateDefaultSubobject<UDestructibleComponent>("Destructible");

	RootComponent = Cast<USceneComponent>(DestructibleComponent);

}

// Called when the game starts or when spawned
void ABaseDestructibleSpell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseDestructibleSpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

