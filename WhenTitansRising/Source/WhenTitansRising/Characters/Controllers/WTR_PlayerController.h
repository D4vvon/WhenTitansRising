// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WTR_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class WHENTITANSRISING_API AWTR_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void SetPawn(APawn* InPawn) override;

protected:
	virtual void SetupInputComponent() override;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);

	void Jump();

	void ChangeCrouchState();

	void StartSprint();
	void StopSprint();

	TSoftObjectPtr<class AWTR_BaseCharacter> BaseCharacter;
};
