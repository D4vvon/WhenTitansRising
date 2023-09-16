// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Interactive/InteractiveActor.h"
#include "Characters/WTR_BaseCharacter.h"
#include "Components/CapsuleComponent.h"

void AInteractiveActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsValid(InteractionVolume))
	{
		InteractionVolume->OnComponentBeginOverlap.AddDynamic(this, &AInteractiveActor::OnInteractionVolumeOverlapBegin);
		InteractionVolume->OnComponentEndOverlap.AddDynamic(this, &AInteractiveActor::OnInteractionVolumeOverlapEnd);
	}
}

void AInteractiveActor::OnInteractionVolumeOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AWTR_BaseCharacter* BaseCharacter = Cast<AWTR_BaseCharacter>(OtherActor);
	if (!IsValid(BaseCharacter))
	{
		return;
	}

	if (Cast<UCapsuleComponent>(OtherComp) != BaseCharacter->GetCapsuleComponent())
	{
		return;
	}

	BaseCharacter->RegisterInteractiveActor(this);
}

void AInteractiveActor::OnInteractionVolumeOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AWTR_BaseCharacter* BaseCharacter = Cast<AWTR_BaseCharacter>(OtherActor);
	if (!IsValid(BaseCharacter))
	{
		return;
	}

	if (Cast<UCapsuleComponent>(OtherComp) != BaseCharacter->GetCapsuleComponent())
	{
		return;
	}

	BaseCharacter->UnRegisterInteractiveActor(this);
}


