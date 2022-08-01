// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AICharacter.h"
#include "Perception/PawnSensingComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"


// Sets default values
AAICharacter::AAICharacter()
{
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>("PawnSensingComp");
}


void AAICharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	PawnSensingComp->OnSeePawn.AddDynamic(this, &AAICharacter::OnPawnSeen);
}


void AAICharacter::OnPawnSeen(APawn* Pawn)
{
	AAIController* AIC = Cast<AAIController>(GetController());
	DrawDebugString(GetWorld(), GetActorLocation(), "PLAYER SPOTTED", nullptr, FColor::Red, 4.f, true);

	if (AIC)
	{
		UBlackboardComponent* BBComp = AIC->GetBlackboardComponent();
		BBComp->SetValueAsObject("TargetActor", Pawn);
		DrawDebugString(GetWorld(), GetActorLocation(), "PLAYER SPOTTED", nullptr, FColor::White, 4.f, true);
	}
}