// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AICharacter.generated.h"

class UPawnSensingComponent;


UCLASS()
class ACTIONGAME_API AAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AAICharacter();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UPawnSensingComponent* PawnSensingComp;

	virtual void PostInitializeComponents() override;

	UFUNCTION()
		void OnPawnSeen(APawn* Pawn);
};
