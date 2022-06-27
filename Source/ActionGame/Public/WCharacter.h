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
	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* CameraComp;

	// movement
	void MoveForward(float Value);
	void MoveRight(float Value);

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
