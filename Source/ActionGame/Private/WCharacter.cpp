// Fill out your copyright notice in the Description page of Project Settings.


#include "WCharacter.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
AWCharacter::AWCharacter()
{
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	GetCharacterMovement()->bOrientRotationToMovement = true;

	bUseControllerRotationYaw = false;

}


// Called to bind functionality to input
void AWCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// just movement
	PlayerInputComponent->BindAxis("MoveForward", this, &AWCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AWCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	// attack
	PlayerInputComponent->BindAction("NormalAttack", IE_Pressed, this, &AWCharacter::NormalAttack);

	// skill
	PlayerInputComponent->BindAction("CastSkill1", IE_Pressed, this, &AWCharacter::CastSkill1);

}


// Movement part
void AWCharacter::MoveForward(float Value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	AddMovementInput(ControlRot.Vector(), Value);
}


void AWCharacter::MoveRight(float Value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);

	AddMovementInput(RightVector, Value);
}


// Attack part
void AWCharacter::NormalAttack()
{
	PlayAnimMontage(NormalAttackAnim);

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AWCharacter::NormalAttack_TimeElapsed, 0.2f);

	// I am not so sure about we need to clear the timer after using or not
	// I guess the timer will clear itself after running?
	// Maybe we should clear after a loop?
	// GetWorldTimerManager().ClearTimer(TimerHandle)
}


void AWCharacter::NormalAttack_TimeElapsed()
{
	// pass
}


// Skill part
void AWCharacter::CastSkill1()
{
	PlayAnimMontage(CastSkill1Anim);

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AWCharacter::CastSkill1_TimeElapsed, 0.25f);

	// GetWorldTimerManager().ClearTimer(TimerHandle)
}


void AWCharacter::CastSkill1_TimeElapsed()
{
	// pass
}
