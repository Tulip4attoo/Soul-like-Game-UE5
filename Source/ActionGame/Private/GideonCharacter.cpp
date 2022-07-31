// Fill out your copyright notice in the Description page of Project Settings.


#include "GideonCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


AGideonCharacter::AGideonCharacter()
{
	MovementComp = GetCharacterMovement();
}

void AGideonCharacter::BeginPlay()
{
	Super::BeginPlay();
}


// Called to bind functionality to input
void AGideonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AGideonCharacter::Jump);

	// attack
	PlayerInputComponent->BindAction("NormalAttack", IE_Pressed, this, &AGideonCharacter::NormalAttack);

	// skill
	PlayerInputComponent->BindAction("CastSkill1", IE_Pressed, this, &AGideonCharacter::CastSkill1);
	PlayerInputComponent->BindAction("CastSkill2", IE_Pressed, this, &AGideonCharacter::CastSkill2);
}


void AGideonCharacter::Jump()
{
	Super::Jump();
}

// Attack part
void AGideonCharacter::NormalAttack()
{
	Super::NormalAttack();
	MovementComp->SetMovementMode(MOVE_None);
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AGideonCharacter::NormalAttack_TimeElapsed, NormalAttackTime);

	// I am not so sure about we need to clear the timer after using or not
	// I guess the timer will clear itself after running?
	// Maybe we should clear after a loop?
	// GetWorldTimerManager().ClearTimer(TimerHandle)
}


void AGideonCharacter::NormalAttack_TimeElapsed()
{
	Super::NormalAttack_TimeElapsed();
	MovementComp->SetMovementMode(MOVE_Walking);

	// pass
}


// Skill part
void AGideonCharacter::CastSkill1()
{
	Super::CastSkill1();
	MovementComp->SetMovementMode(MOVE_None);
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AGideonCharacter::NormalAttack_TimeElapsed, CastSkill1Time);
}


void AGideonCharacter::CastSkill1_TimeElapsed()
{
	Super::CastSkill1_TimeElapsed();
	MovementComp->SetMovementMode(MOVE_Walking);
	// pass
}


// Skill part
void AGideonCharacter::CastSkill2()
{
	Super::CastSkill1();
	MovementComp->SetMovementMode(MOVE_None);
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AGideonCharacter::NormalAttack_TimeElapsed, CastSkill2Time);
}


void AGideonCharacter::CastSkill2_TimeElapsed()
{
	Super::CastSkill1_TimeElapsed();
	MovementComp->SetMovementMode(MOVE_Walking);
	// pass
}
