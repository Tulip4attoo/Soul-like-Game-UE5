// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WCharacter.generated.h"


class UCameraComponent;
class USpringArmComponent;
class USAttributeComponent;
class UInteractionComponent;


UCLASS(ABSTRACT)
class ACTIONGAME_API AWCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWCharacter();

protected:
	// attached components
	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
		UInteractionComponent* InteractionComp;

	// attack
	UPROPERTY(EditAnywhere, Category = "Attack")
		UAnimMontage* NormalAttackAnim;

	// skill-related things
	UPROPERTY(EditAnywhere, Category = "Skill")
		UAnimMontage* CastSkill1Anim;


	FTimerHandle TimerHandle;

	// movement
	void MoveForward(float Value);
	void MoveRight(float Value);

	// cast attack
	virtual void NormalAttack();
	virtual void NormalAttack_TimeElapsed();

	// cast skill
	virtual void CastSkill1();
	virtual void CastSkill1_TimeElapsed();

	// change equipment
	void PrimaryInteract();

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
