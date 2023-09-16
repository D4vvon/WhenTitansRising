// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Animations/WTR_BaseCharacterAnimInstance.h"
#include "../WTR_BaseCharacter.h"
#include "../Components/WTRBaseCharacterMovementComp.h"

void UWTR_BaseCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	checkf(TryGetPawnOwner()->IsA<AWTR_BaseCharacter>(), TEXT("Crush"));

	BaseCharacter = StaticCast<AWTR_BaseCharacter*>(TryGetPawnOwner());
}

void UWTR_BaseCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (!BaseCharacter.IsValid())
	{
		return;
	}

	UWTRBaseCharacterMovementComp* CharacterMovement = BaseCharacter->GetBaseCharacterMovementCompoment();

	Speed = CharacterMovement->Velocity.Size();
	bIsFalling = CharacterMovement->IsFalling();
	bIsCrouch = CharacterMovement->IsCrouching();
	bIsSprinting = CharacterMovement->IsSprinting();
	bIsSwimming = CharacterMovement->IsSwimming();
}
