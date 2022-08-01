// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;


UCLASS()
class ACTIONGAME_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseProjectile();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere)
		UProjectileMovementComponent* MovementComp;

	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* EffectComp;

};
