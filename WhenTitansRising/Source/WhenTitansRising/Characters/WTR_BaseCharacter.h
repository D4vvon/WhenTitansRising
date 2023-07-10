// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WTR_BaseCharacter.generated.h"

UCLASS(Abstract, NotBlueprintable)
class WHENTITANSRISING_API AWTR_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AWTR_BaseCharacter(const FObjectInitializer& ObjectInitializer);
	
	virtual void Tick(float DeltaTime) override;

	virtual void MoveForward(float Value) {};
	virtual void MoveRight(float Value) {};
	virtual void Turn(float Value) {};
	virtual void LookUp(float Value) {};

	virtual void ChangeCrouchState();

	virtual void StartSprint();
	virtual void StopSprint();
	FORCEINLINE bool GetIsSprinting() { return bIsSprinting; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character | Movement")
	float SprintSpeed = 1200.0f;

	virtual bool CanSprint();

private:
	float DefaultMaxMovementSpeed = 0.0f;
	bool bIsSprintRequested = false;
	bool bIsSprinting = false;

};
