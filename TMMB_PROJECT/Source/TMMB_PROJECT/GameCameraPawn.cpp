// Fill out your copyright notice in the Description page of Project Settings.

#include "GameCameraPawn.h"

#include "Engine/Engine.h"
#include "Camera/CameraComponent.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"


// Sets default values
AGameCameraPawn::AGameCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");

}

// Called when the game starts or when spawned
void AGameCameraPawn::BeginPlay()
{

	Super::BeginPlay();

	//APlayerController * PlayerZeroReference = GetWorld()->GetFirstPlayerController();

	//PlayerZeroReference->SetViewTargetWithBlend(this);

}

// Called every frame
void AGameCameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGameCameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

