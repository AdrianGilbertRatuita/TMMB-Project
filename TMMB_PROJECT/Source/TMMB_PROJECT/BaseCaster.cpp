// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCaster.h"

//
#include "GameManager.h"
#include "GameCameraPawn.h"

//
#include "Engine.h"

//
#include "Components/SceneComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"

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
	
	//// Create Player
	UGameplayStatics::CreatePlayer(GetWorld());

	// Inherit Springarm controls
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->bInheritYaw = true;

	// Enable Necessary Capsule Properties
	CapsuleComponent->SetEnableGravity(true);
	CapsuleComponent->SetSimulatePhysics(true);
	CapsuleComponent->SetCollisionProfileName("Pawn");
	CapsuleComponent->SetMassOverrideInKg();
	CapsuleComponent->BodyInstance.bLockXRotation = true;
	CapsuleComponent->BodyInstance.bLockYRotation = true;
	CapsuleComponent->BodyInstance.SetDOFLock(EDOFMode::Default);
	CapsuleComponent->SetMassOverrideInKg(NAME_None, 50.0f, true);
	CapsuleComponent->SetAngularDamping(1.0f);

	//for (FConstPlayerControllerIterator Iterator = GetWorld()->GetFirstPlayerController)

	//Get First GameManager

	if (GetWorld())
	{

		for (FActorIterator Iterator = FActorIterator(GetWorld(), AGameManager::StaticClass(), EActorIteratorFlags::AllActors); Iterator; ++Iterator)
		{

			GameManager = Cast<AGameManager>(*Iterator);

		}

	}

	// Make sure a reference to the Game Manager Exists
	if (GameManager)
	{

		// Assign Control to the necessary controller 
		GameManager->AssignControl(this);

	}

	if (GetWorld())
	{

		for (FActorIterator Iterator = FActorIterator(GetWorld(), AGameCameraPawn::StaticClass(), EActorIteratorFlags::AllActors); Iterator; ++Iterator)
		{

			UGameplayStatics::GetPlayerController(GetWorld(), PlayerNumber)->SetViewTargetWithBlend(*Iterator);

		}

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

}

void ABaseCaster::LeftXMove(float AxisValue)
{

	LeftMovementX = AxisValue;
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("DIRECTION: %f"), AxisValue));
	if (AxisValue != 0)
	{

		//
		FVector Direction = GetControlRotation().Quaternion() * FVector(0, AxisValue, 0);
		Direction.Z = 0;


		FVector FinalPosition = GetActorLocation() + Direction * MovementSpeed * GetWorld()->GetDeltaSeconds();
		this->SetActorLocation(FinalPosition);

		ApplyRotation();

	}

}

void ABaseCaster::LeftYMove(float AxisValue)
{

	LeftMovementY = AxisValue;

	if (AxisValue != 0)
	{

		//
		FVector Direction = GetControlRotation().Quaternion() * FVector(AxisValue, 0, 0);
		Direction.Z = 0;

		FVector FinalPosition = GetActorLocation() + Direction * MovementSpeed * GetWorld()->GetDeltaSeconds();
		this->SetActorLocation(FinalPosition);

		ApplyRotation();

	}

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

void ABaseCaster::ApplyRotation()
{

	FRotator RotationFix = GetControlRotation();

	if (LeftMovementY != 0 || LeftMovementX != 0)
	{

		float Rotation = 0;
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("ROTATION X:%f, Y: %f"), LeftMovementY, LeftMovementX));
		Rotation = (atan2(LeftMovementX, LeftMovementY) * 180 / PI);

		// Rotation
		
		RotationFix.Yaw += Rotation;
		RotationFix.Pitch = 0;
		RotationFix.Roll = 0;
		RotationFix.Roll = 0;

	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Current Rotation: %s"), *GetControlRotation().ToString()));
	this->SetActorRotation(FMath::Lerp(GetActorRotation(), RotationFix, 0.1f));

}

void ABaseCaster::CooldownOff()
{

	bCanShoot = true;

}
