// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Controllers/WTR_PlayerController.h"
#include "../WTR_BaseCharacter.h"

void AWTR_PlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	BaseCharacter = Cast<AWTR_BaseCharacter>(InPawn);
}

void AWTR_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AWTR_PlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AWTR_PlayerController::MoveRight);
	InputComponent->BindAxis("Turn", this, &AWTR_PlayerController::Turn);
	InputComponent->BindAxis("LookUp", this, &AWTR_PlayerController::LookUp);

	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AWTR_PlayerController::Jump);

	InputComponent->BindAction("Crouch", EInputEvent::IE_Pressed, this, &AWTR_PlayerController::ChangeCrouchState);

	InputComponent->BindAction("Sprint", EInputEvent::IE_Pressed, this, &AWTR_PlayerController::StartSprint);
	InputComponent->BindAction("Sprint", EInputEvent::IE_Released, this, &AWTR_PlayerController::StopSprint);

}

void AWTR_PlayerController::MoveForward(float Value)
{
	if (BaseCharacter.IsValid())
	{
		BaseCharacter->MoveForward(Value);
	}
}

void AWTR_PlayerController::MoveRight(float Value)
{
	if (BaseCharacter.IsValid())
	{
		BaseCharacter->MoveRight(Value);
	}
}

void AWTR_PlayerController::Turn(float Value)
{
	if (BaseCharacter.IsValid())
	{
		BaseCharacter->Turn(Value);
	}
}

void AWTR_PlayerController::LookUp(float Value)
{
	if (BaseCharacter.IsValid())
	{
		BaseCharacter->LookUp(Value);
	}
}

void AWTR_PlayerController::Jump()
{
	if (BaseCharacter.IsValid())
	{
		BaseCharacter->Jump();
	}
}

void AWTR_PlayerController::ChangeCrouchState()
{
	if (BaseCharacter.IsValid())
	{
		BaseCharacter->ChangeCrouchState();
	}
}

void AWTR_PlayerController::StartSprint()
{
	if (BaseCharacter.IsValid())
	{
		BaseCharacter->StartSprint();
	}
}

void AWTR_PlayerController::StopSprint()
{
	if (BaseCharacter.IsValid())
	{
		BaseCharacter->StopSprint();
	}
}
