// Fill out your copyright notice in the Description page of Project Settings.


#include "MKCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


AMKCharacter::AMKCharacter()
{
	MovementComp = GetCharacterMovement();
}

void AMKCharacter::BeginPlay()
{
	Super::BeginPlay();
}


// Called to bind functionality to input
void AMKCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// attack
	PlayerInputComponent->BindAction("NormalAttack", IE_Pressed, this, &AMKCharacter::NormalAttack);

	// skill
	PlayerInputComponent->BindAction("CastSkill1", IE_Pressed, this, &AMKCharacter::CastSkill1);
}

// Attack part
void AMKCharacter::NormalAttack()
{
	Super::NormalAttack();
	MovementComp->SetMovementMode(MOVE_None);
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMKCharacter::NormalAttack_TimeElapsed, NormalAttackTime);

	// I am not so sure about we need to clear the timer after using or not
	// I guess the timer will clear itself after running?
	// Maybe we should clear after a loop?
	// GetWorldTimerManager().ClearTimer(TimerHandle)
}


void AMKCharacter::NormalAttack_TimeElapsed()
{
	Super::NormalAttack_TimeElapsed();
	MovementComp->SetMovementMode(MOVE_Walking);

	// pass
}


// Skill part
void AMKCharacter::CastSkill1()
{
	Super::CastSkill1();
	MovementComp->SetMovementMode(MOVE_None);
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMKCharacter::NormalAttack_TimeElapsed, CastSkill1Time);
}


void AMKCharacter::CastSkill1_TimeElapsed()
{
	Super::CastSkill1_TimeElapsed();
	MovementComp->SetMovementMode(MOVE_Walking);
	// pass
}

