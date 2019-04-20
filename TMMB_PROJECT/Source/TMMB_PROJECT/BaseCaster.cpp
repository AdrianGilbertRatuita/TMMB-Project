// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCaster.h"

//
#include "GameManager.h"

//
#include "Engine.h"

//
#include "Components/SceneComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


// Sets default values
ABaseCaster::ABaseCaster()
{

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	StaffMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Staff");
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");

	//
	RootComponent = Cast<USceneComponent>(CapsuleComponent);
	StaffMeshComponent->SetupAttachment(RootComponent);
	SkeletalMeshComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ABaseCaster::BeginPlay()
{

	Super::BeginPlay();
	
	// Create Player
	UGameplayStatics::CreatePlayer(GetWorld());

	// Enable Necessary Capsule Properties
	CapsuleComponent->SetEnableGravity(true);
	CapsuleComponent->SetSimulatePhysics(true);
	CapsuleComponent->SetCollisionProfileName("Pawn");
	CapsuleComponent->BodyInstance.bLockXRotation = true;
	CapsuleComponent->BodyInstance.bLockYRotation = true;
	CapsuleComponent->SetMassOverrideInKg();
	CapsuleComponent->BodyInstance.SetDOFLock(EDOFMode::Default);
	CapsuleComponent->SetMassOverrideInKg(NAME_None, 50.0f, true);
	CapsuleComponent->SetAngularDamping(1.0f);

	for (FActorIterator Iterator = FActorIterator(GetWorld(), AGameManager::StaticClass(), EActorIteratorFlags::AllActors); Iterator; ++Iterator)
	{

		GameManager = Cast<AGameManager>(*Iterator);

	}

	// Make sure a reference to the Game Manager Exists
	if (GameManager)
	{

		// Assign Control to the necessary controller 
		GameManager->AssignControl(this);

	}

}

// Called every frame
void ABaseCaster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("DIRECTION: %f"), CurrentDirection));*/

}

// Called to bind functionality to input
void ABaseCaster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent = PlayerInputComponent;

	InputComponent->BindAxisKey(EKeys::Gamepad_LeftX, this, &ABaseCaster::LeftXMove);
	InputComponent->BindAxisKey(EKeys::Gamepad_LeftY, this, &ABaseCaster::LeftYMove);

	InputComponent->BindAxisKey(EKeys::Gamepad_RightX, this, &ABaseCaster::RightXMove);
	InputComponent->BindAxisKey(EKeys::Gamepad_RightY, this, &ABaseCaster::RightYMove);

}

void ABaseCaster::LeftXMove(float AxisValue)
{

	LeftMovementX = AxisValue;

	ApplyMovement();

}

void ABaseCaster::LeftYMove(float AxisValue)
{

	LeftMovementY = AxisValue;

	ApplyMovement();

}

void ABaseCaster::RightXMove(float AxisValue)
{

	RightMovementX = AxisValue;

}

void ABaseCaster::RightYMove(float AxisValue)
{

	RightMovementY = AxisValue;

}

void ABaseCaster::ApplyMovement()
{

	FVector Direction = FVector(LeftMovementY, LeftMovementX, 0);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("%s"), *Direction.ToString()));

	if (LeftMovementY != 0 || LeftMovementX != 0)
	{

		FVector FinalLocation = GetActorLocation() + Direction * MovementSpeed * GetWorld()->GetTimeSeconds();
		SetActorLocation(FinalLocation);
		
	}

	if (RightMovementX == 0 || RightMovementY == 0)
	{

		ApplyRotation(LeftMovementX, LeftMovementY);

	}

}

void ABaseCaster::ApplyRotation(float X, float Y)
{

	FRotator RotationFix = GetActorRotation();
	RotationFix.Yaw = atan2f(X, Y) * 180 / PI;

	SetActorRotation(FMath::Lerp(GetActorRotation(), RotationFix, 0.1f));

}


