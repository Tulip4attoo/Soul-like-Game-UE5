// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MeleeMinion_AIController.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONGAME_API AMeleeMinion_AIController : public AAIController
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditAnywhere, Category = "AI")
		UBehaviorTree* BehaviorTree;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
