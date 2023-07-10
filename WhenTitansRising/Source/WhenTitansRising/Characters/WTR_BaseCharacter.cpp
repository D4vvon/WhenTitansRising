// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/WTR_BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AWTR_BaseCharacter::AWTR_BaseCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void AWTR_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

bool AWTR_BaseCharacter::CanSprint()
{
	return true;
}

void AWTR_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsSprintRequested && !bIsSprinting && CanSprint())
	{
		bIsSprinting = true;
		DefaultMaxMovementSpeed = GetCharacterMovement()->MaxWalkSpeed;
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	}

	if (!bIsSprintRequested && bIsSprinting)
	{
		bIsSprinting = false;
		GetCharacterMovement()->MaxWalkSpeed = DefaultMaxMovementSpeed;
	}
}

void AWTR_BaseCharacter::ChangeCrouchState()
{
	if (GetCharacterMovement()->IsCrouching())
	{
		UnCrouch();
	}
	else
	{
		Crouch();
	}
}

void AWTR_BaseCharacter::StartSprint()
{
	bIsSprintRequested = true;
	GetCharacterMovement()->bForceMaxAccel = 1;
}

void AWTR_BaseCharacter::StopSprint()
{
	bIsSprintRequested = false;
	GetCharacterMovement()->bForceMaxAccel = 0;
}

