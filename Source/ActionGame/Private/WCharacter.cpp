// Fill out your copyright notice in the Description page of Project Settings.


#include "WCharacter.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "InteractionComponent.h"
#include "AttributeComponent.h"


// Sets default values
AWCharacter::AWCharacter()
{
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	InteractionComp = CreateDefaultSubobject<UInteractionComponent>("InteractionComp");
	AttributeComp = CreateDefaultSubobject<UAttributeComponent>("AttributeComp");

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;

}


void AWCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	AttributeComp->OnHealthChanged.AddDynamic(this, &AWCharacter::OnHealthChanged);
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
	PlayerInputComponent->BindAction("CastSkill2", IE_Pressed, this, &AWCharacter::CastSkill2);

	// change equipment
	PlayerInputComponent->BindAction("PrimaryInteract", IE_Pressed, this, &AWCharacter::PrimaryInteract);
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

	// GetWorldTimerManager().SetTimer(TimerHandle, this, &AWCharacter::NormalAttack_TimeElapsed, 0.2f);

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
}


void AWCharacter::CastSkill1_TimeElapsed()
{
}


void AWCharacter::CastSkill2()
{
	PlayAnimMontage(CastSkill1Anim);
}


void AWCharacter::CastSkill2_TimeElapsed()
{
}

// change equipment
void AWCharacter::PrimaryInteract()
{
	if (InteractionComp)
	{
		InteractionComp->PrimaryInteract();
	}
}


void AWCharacter::OnHealthChanged(AActor* InstigatorActor,
	UAttributeComponent* OwningComp, float NewHealth, float Delta)
{
	if (NewHealth <= 0.f)
	{
		APlayerController* PlayerController = Cast<APlayerController>(GetController());
		DisableInput(PlayerController);
	}
}
