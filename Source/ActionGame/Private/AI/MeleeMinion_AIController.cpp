// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/MeleeMinion_AIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"


// Called when the game starts or when spawned
void AMeleeMinion_AIController::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(BehaviorTree);

	APawn* MyPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (MyPawn)
	{
	GetBlackboardComponent()->SetValueAsObject("TargetActor", MyPawn);
	}

}

