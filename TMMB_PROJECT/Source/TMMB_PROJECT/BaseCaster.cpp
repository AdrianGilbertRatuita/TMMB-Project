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

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ABaseCaster::ABaseCaster()
{

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	StaffMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Staff");
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");	
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");

	//
	RootComponent = Cast<USceneComponent>(CapsuleComponent);
	StaffMeshComponent->SetupAttachment(RootComponent);
	SkeletalMeshComponent->SetupAttachment(RootComponent);
	SpringArmComponent->SetupAttachment(RootComponent);

	//
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);

}

// Called when the game starts or when spawned
void ABaseCaster::BeginPlay()
{

	Super::BeginPlay();
	
	// Create Player
	UGameplayStatics::CreatePlayer(GetWorld());

	// Inherit Springarm controls
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->bInheritYaw = true;

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

	// Get First GameManager
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

	//
	FVector Direction = GetControlRotation().Quaternion() * FVector(0, AxisValue, 0);
	Direction.Z = 0;


	FVector FinalPosition = GetActorLocation() + Direction * MovementSpeed * GetWorld()->GetDeltaSeconds();
	SetActorLocation(FinalPosition);

	ApplyRotation();

}

void ABaseCaster::LeftYMove(float AxisValue)
{

	LeftMovementY = AxisValue;

	//
	FVector Direction = GetControlRotation().Quaternion() * FVector(AxisValue, 0, 0);
	Direction.Z = 0;

	FVector FinalPosition = GetActorLocation() + Direction * MovementSpeed * GetWorld()->GetDeltaSeconds();
	SetActorLocation(FinalPosition);

	ApplyRotation();

}

void ABaseCaster::RightXMove(float AxisValue)
{

	//RightMovementX = AxisValue;

	//ApplyRotation();

}

void ABaseCaster::RightYMove(float AxisValue)
{

	//RightMovementY = AxisValue;

	//ApplyRotation();

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

		ApplyRotation();

	}

}

void ABaseCaster::ApplyRotation()
{

	float Rotation = 0;

	if (LeftMovementY != 0 || LeftMovementX != 0)
	{

		Rotation = (atan2(LeftMovementX, LeftMovementY) * 180 / PI);

		// Rotation
		FRotator RotationFix = GetControlRotation();
		RotationFix.Yaw += Rotation;
		RotationFix.Pitch = 0;
		RotationFix.Roll = 0;

		FRotator CurrentRotation = GetActorRotation();
		SetActorRotation(FMath::Lerp(CurrentRotation, RotationFix, 0.1f));

	}
	//else if (RightMovementX != 0 || RightMovementY != 0)
	//{

	//	Rotation = (atan2(RightMovementY, RightMovementX) * 180 / PI);

	//	// Rotation
	//	FRotator RotationFix = GetControlRotation();
	//	RotationFix.Yaw += Rotation;
	//	RotationFix.Pitch = 0;
	//	RotationFix.Roll = 0;

	//	FRotator CurrentRotation = GetActorRotation();
	//	SetActorRotation(FMath::Lerp(CurrentRotation, RotationFix, 0.1f));

	//}


}


