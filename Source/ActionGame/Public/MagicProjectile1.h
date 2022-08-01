// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseProjectile.h"
#include "MagicProjectile1.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONGAME_API AMagicProjectile1 : public ABaseProjectile
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AMagicProjectile1();

	UFUNCTION()
		void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
