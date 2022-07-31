// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "RangedMinion_AIController.generated.h"

/**
 * 
 */
class UBehaviorTree;


UCLASS()
class ACTIONGAME_API ARangedMinion_AIController : public AAIController
{
	GENERATED_BODY()
	

protected:

	UPROPERTY(EditAnywhere, Category = "AI")
		UBehaviorTree* BehaviorTree;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
