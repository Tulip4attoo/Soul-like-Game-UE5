// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WCharacter.generated.h"


class UCameraComponent;
class USpringArmComponent;
class USAttributeComponent;


UCLASS()
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
	void NormalAttack();
	void NormalAttack_TimeElapsed();
	
	// cast skill
	void CastSkill1();
	void CastSkill1_TimeElapsed();

	// change equipment
	void ChangeEquipment();

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
