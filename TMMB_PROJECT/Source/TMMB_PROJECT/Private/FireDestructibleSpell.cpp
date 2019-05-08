// Fill out your copyright notice in the Description page of Project Settings.

#include "FireDestructibleSpell.h"
#include "Engine.h"
#include "Elementalist.h"
#include "DestructibleComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"

void AFireDestructibleSpell::BeginPlay()
{
	//Super::BeginPlay();
	DestructibleComponent->OnComponentHit.AddDynamic(this, &AFireDestructibleSpell::OnComponentHit2);
	DestructibleComponent->OnComponentBeginOverlap.AddDynamic(this, &AFireDestructibleSpell::OnOverlapBegin);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("BeginPlay")));

	DestructibleComponent->AddImpulse((GetActorForwardVector()*2000) + FVector(0, 0, 800), "None", true);

}

void AFireDestructibleSpell::Tick(float DeltaTime)
{
	// Do stuff
	// This is basically Update() {	};
}

void AFireDestructibleSpell::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("%s"), *OtherActor->GetName()));

	// This is basically onTriggerEnter() {	};
	if (OtherActor->ActorHasTag("Player"))
	{
		// Do stuff bitch
		//FTransform X = GetActorTransform();
		//FMath::
		//GetWorld()->GetDeltaSeconds();
		//FActorSpawnParameters Y;
		//GetWorld()->SpawnActor(/*spawn the blueprint*/)

		FVector test = FVector(1, 1, 1);
		Cast<UPrimitiveComponent>(OtherActor->GetRootComponent())->AddForce(test);
	}
}

void AFireDestructibleSpell::OnComponentHit2(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("BeginPlay")));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("%s"), *OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("%s"), *OtherComp->GetOwner()->GetName()));


	if (OtherActor->ActorHasTag("Player"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("s")));
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("%s"), *OtherActor->GetName()));
		Cast<UPrimitiveComponent>(OtherActor->GetRootComponent())->AddForce(NormalImpulse*-1000);

	}
}

void AFireDestructibleSpell::OnComponentFracture(FVector HitPoint, FVector HitDirection)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Fractured!")));

}
