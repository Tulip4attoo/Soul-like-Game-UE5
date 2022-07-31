// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WCharacter.generated.h"


class UCameraComponent;
class USpringArmComponent;
class UInteractionComponent;
class UAttributeComponent;


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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attribute")
		UAttributeComponent* AttributeComp;

	// attack
	UPROPERTY(EditAnywhere, Category = "Attack")
		UAnimMontage* NormalAttackAnim;

	// skill-related things
	UPROPERTY(EditAnywhere, Category = "Skill")
		UAnimMontage* CastSkill1Anim;


	FTimerHandle TimerHandle;

	virtual void PostInitializeComponents() override;

	// movement
	void MoveForward(float Value);
	void MoveRight(float Value);

	// cast attack
	virtual void NormalAttack();
	virtual void NormalAttack_TimeElapsed();

	// cast skill
	virtual void CastSkill1();
	virtual void CastSkill1_TimeElapsed();

	virtual void CastSkill2();
	virtual void CastSkill2_TimeElapsed();

	// change equipment
	void PrimaryInteract();


	UFUNCTION()
		void OnHealthChanged(AActor* InstigatorActor,
			UAttributeComponent* OwningComp, float NewHealth, float Delta);

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
