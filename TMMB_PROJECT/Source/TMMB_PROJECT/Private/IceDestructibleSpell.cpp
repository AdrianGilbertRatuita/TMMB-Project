// Fill out your copyright notice in the Description page of Project Settings.

#include "IceDestructibleSpell.h"

void AIceDestructibleSpell::Tick(float DeltaTime)
{
	// Do stuff
	// This is basically Update() {	};
}

void AIceDestructibleSpell::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	// This is basically onTriggerEnter() {	};
	if (OtherActor->ActorHasTag("Player"))
	{
		// Do stuff bitch
		FTransform X = GetActorTransform();
		//FMath::
		//GetWorld()->GetDeltaSeconds();
		FActorSpawnParameters Y;
		//GetWorld()->SpawnActor(/*spawn the blueprint*/)
	}
}
