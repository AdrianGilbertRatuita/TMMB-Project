// Fill out your copyright notice in the Description page of Project Settings.

#include "IceDestructibleSpell.h"
#include "Engine.h"
#include "Elementalist.h"
#include "DestructibleComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"

void AIceDestructibleSpell::BeginPlay()
{
	//Super::BeginPlay();
	DestructibleComponent->OnComponentHit.AddDynamic(this, &AIceDestructibleSpell::OnComponentHit2);
	DestructibleComponent->OnComponentBeginOverlap.AddDynamic(this, &AIceDestructibleSpell::OnOverlapBegin);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("BeginPlay")));
}

void AIceDestructibleSpell::Tick(float DeltaTime)
{
	// Do stuff
	// This is basically Update() {	};
}

void AIceDestructibleSpell::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
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

void AIceDestructibleSpell::OnComponentHit2(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("s")));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("%s"), *OtherActor->GetName()));

	if (OtherActor->ActorHasTag("Player"))
	{

		Cast<UPrimitiveComponent>(OtherActor->GetRootComponent())->AddForce(NormalImpulse*-1000);

	}
}

void AIceDestructibleSpell::OnComponentFracture(FVector HitPoint, FVector HitDirection)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Fractured!")));

}