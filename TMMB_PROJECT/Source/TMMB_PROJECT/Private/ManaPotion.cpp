// Fill out your copyright notice in the Description page of Project Settings.

#include "ManaPotion.h"

#include "Engine.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AManaPotion::AManaPotion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");

}

// Called when the game starts or when spawned
void AManaPotion::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AManaPotion::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += RotationSpeed * GetWorld()->GetDeltaSeconds();

	SetActorRotation(FMath::Lerp(GetActorRotation(), NewRotation, 0.1f));

}

