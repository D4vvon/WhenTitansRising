// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Components/WTRBaseCharacterMovementComp.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"

float UWTRBaseCharacterMovementComp::GetMaxSpeed() const
{
	float Result = Super::GetMaxSpeed();
	
	if (bIsSprinting)
	{
		Result = SprintSpeed;
	}
	else if (IsSwimming())
	{
		Result = SwimmingSpeed;
	}
	return Result;
}

void UWTRBaseCharacterMovementComp::StartSprint()
{
	bIsSprinting = true;
	bForceMaxAccel = 1;
}

void UWTRBaseCharacterMovementComp::StopSprint()
{
	bIsSprinting = false;
	bForceMaxAccel = 0;
}

void UWTRBaseCharacterMovementComp::AttachToLadder(const ALadder* Ladder)
{
	CurrentLadder = Ladder;
	SetMovementMode(MOVE_Custom, (uint8)ECustomMovementMode::CMOVE_Ladder);
}

void UWTRBaseCharacterMovementComp::DetachFromLadder()
{
	SetMovementMode(MOVE_Falling);
}

bool UWTRBaseCharacterMovementComp::IsOnLadder() const
{
	return UpdatedComponent && MovementMode == MOVE_Custom && CustomMovementMode == (uint8)ECustomMovementMode::CMOVE_Ladder;
}

void UWTRBaseCharacterMovementComp::OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PreviousMovementMode, PreviousCustomMode);

	if (MovementMode == MOVE_Swimming)
	{
		CharacterOwner->GetCapsuleComponent()->SetCapsuleSize(SwimmingCapsuleRadius, SwimmingCapsuleHalfHeight);
		RotationRate = SwimmingRotationRate;
	}
	else if (PreviousMovementMode == MOVE_Swimming)
	{
		ACharacter* DefaultCharacter = CharacterOwner->GetClass()->GetDefaultObject<ACharacter>();
		CharacterOwner->GetCapsuleComponent()->SetCapsuleSize(DefaultCharacter->GetCapsuleComponent()->GetUnscaledCapsuleRadius(), DefaultCharacter->GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight(), true);
		RotationRate = BaseRotationRate;
	}

	if (PreviousMovementMode == MOVE_Custom && PreviousCustomMode == (uint8)ECustomMovementMode::CMOVE_Ladder)
	{
		CurrentLadder = nullptr;
	}
}

void UWTRBaseCharacterMovementComp::PhysCustom(float DeltaTime, int32 Iterations)
{
	
}
