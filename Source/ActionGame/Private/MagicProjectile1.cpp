// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicProjectile1.h"
#include "AttributeComponent.h"


AMagicProjectile1::AMagicProjectile1()
{
}


void AMagicProjectile1::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != GetInstigator())
	{
		UAttributeComponent* AttributeComp = Cast<UAttributeComponent>(OtherActor->GetComponentByClass(UAttributeComponent::StaticClass()));
		if (AttributeComp)
		{
			AttributeComp->ApplyHealthChange(-20.f);
		}
	}
}
