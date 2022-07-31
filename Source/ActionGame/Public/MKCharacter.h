// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WCharacter.h"
#include "MKCharacter.generated.h"

/**
 * 
 */
class UCharacterMovementComponent;


UCLASS()
class ACTIONGAME_API AMKCharacter : public AWCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMKCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(VisibleAnywhere)
		UCharacterMovementComponent* MovementComp;
	
	UPROPERTY(EditAnywhere, Category = "Attack")
		float NormalAttackTime;

	UPROPERTY(EditAnywhere, Category = "Skill")
		float CastSkill1Time;

	UPROPERTY(EditAnywhere, Category = "Skill")
		float CastSkill2Time;

	virtual void BeginPlay() override;

	void NormalAttack() override;
	void NormalAttack_TimeElapsed() override;

	// cast skill
	void CastSkill1() override;
	void CastSkill1_TimeElapsed() override;

};
