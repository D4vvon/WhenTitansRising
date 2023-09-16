// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/WTR_BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/WTRBaseCharacterMovementComp.h"
#include "Components/LedgeDetectionVaultingComponent.h"

AWTR_BaseCharacter::AWTR_BaseCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UWTRBaseCharacterMovementComp>(ACharacter::CharacterMovementComponentName))
{
	WTRBaseCharacterMovementComponent = StaticCast<UWTRBaseCharacterMovementComp*>(GetCharacterMovement());

	VaultingLedgeDetector = CreateDefaultSubobject<ULedgeDetectionVaultingComponent>(TEXT("VaultingLedgeDetetor"));
}

void AWTR_BaseCharacter::RegisterInteractiveActor(AInteractiveActor* InteractiveActor)
{
	AvailableInteractiveActors.Add(InteractiveActor);
}

void AWTR_BaseCharacter::UnRegisterInteractiveActor(AInteractiveActor* InteractiveActor)
{
	AvailableInteractiveActors.Remove(InteractiveActor);
}

void AWTR_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

bool AWTR_BaseCharacter::CanSprint()
{
	if (GetCharacterMovement()->IsFalling())
	{
		return false;
	}
	if (GetCharacterMovement()->IsSwimming())
	{
		return false;
	}
	return true;
}

void AWTR_BaseCharacter::TryChangeSprintState()
{
	if (bIsSprintRequested && !WTRBaseCharacterMovementComponent->IsSprinting() && CanSprint())
	{
		WTRBaseCharacterMovementComponent->StartSprint();
	}

	if (!bIsSprintRequested && WTRBaseCharacterMovementComponent->IsSprinting())
	{
		WTRBaseCharacterMovementComponent->StopSprint();
	}
}

void AWTR_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TryChangeSprintState();
}

void AWTR_BaseCharacter::ChangeCrouchState()
{
	if (!GetCharacterMovement()->IsSwimming())
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
}

void AWTR_BaseCharacter::StartSprint()
{
	bIsSprintRequested = true;
}

void AWTR_BaseCharacter::StopSprint()
{
	bIsSprintRequested = false;
}

void AWTR_BaseCharacter::ClimbLadder(float Value)
{
	
}

void AWTR_BaseCharacter::InteractWithLadder()
{
	
}

void AWTR_BaseCharacter::Mantle()
{
	FLedgeDesciption LedgeDescription;
	if (VaultingLedgeDetector->DetectLedge(LedgeDescription))
	{

	}
}

