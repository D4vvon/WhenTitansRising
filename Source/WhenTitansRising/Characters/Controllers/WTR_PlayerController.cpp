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

	InputComponent->BindAction("Mantle", EInputEvent::IE_Pressed, this, &AWTR_PlayerController::Mantle);
	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AWTR_PlayerController::Jump);

	InputComponent->BindAction("Crouch", EInputEvent::IE_Pressed, this, &AWTR_PlayerController::ChangeCrouchState);

	InputComponent->BindAction("Sprint", EInputEvent::IE_Pressed, this, &AWTR_PlayerController::StartSprint);
	InputComponent->BindAction("Sprint", EInputEvent::IE_Released, this, &AWTR_PlayerController::StopSprint);

	InputComponent->BindAxis("SwimForward", this, &AWTR_PlayerController::SwimForward);
	InputComponent->BindAxis("SwimRight", this, &AWTR_PlayerController::SwimRight);
	InputComponent->BindAxis("SwimUp", this, &AWTR_PlayerController::SwimUp);

	InputComponent->BindAxis("ClimbLadderUp", this, &AWTR_PlayerController::ClimbLadder);
	InputComponent->BindAction("InteractWithLadder", EInputEvent::IE_Pressed, this, &AWTR_PlayerController::InteractWithLadder);

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

void AWTR_PlayerController::ClimbLadder(float Value)
{
	if (BaseCharacter.IsValid())
	{
		BaseCharacter->ClimbLadder(Value);
	}
}

void AWTR_PlayerController::InteractWithLadder()
{
	if (BaseCharacter.IsValid())
	{
		BaseCharacter->InteractWithLadder();
	}
}

void AWTR_PlayerController::Mantle()
{
	if (BaseCharacter.IsValid())
	{
		BaseCharacter->Mantle();
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

void AWTR_PlayerController::SwimForward(float Value)
{
	if (BaseCharacter.IsValid())
	{
		BaseCharacter->SwimForward(Value);
	}
}

void AWTR_PlayerController::SwimRight(float Value)
{
	if (BaseCharacter.IsValid())
	{
		BaseCharacter->SwimRight(Value);
	}
}

void AWTR_PlayerController::SwimUp(float Value)
{
	if (BaseCharacter.IsValid())
	{
		BaseCharacter->SwimUp(Value);
	}
}
