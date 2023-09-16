// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WTR_BaseCharacter.generated.h"

class AInteractiveActor;
class UWTRBaseCharacterMovementComp;

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

	virtual void SwimForward(float Value) {};
	virtual void SwimRight(float Value) {};
	virtual void SwimUp(float Value) {};

	virtual void ClimbLadder(float Value);
	virtual void InteractWithLadder();

	virtual void Mantle();

	FORCEINLINE UWTRBaseCharacterMovementComp* GetBaseCharacterMovementCompoment() { return WTRBaseCharacterMovementComponent; }

	void RegisterInteractiveActor(AInteractiveActor* InteractiveActor);
	void UnRegisterInteractiveActor(AInteractiveActor* InteractiveActor);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character | Movement")
	float SprintSpeed = 1200.0f;

	virtual bool CanSprint();

	UWTRBaseCharacterMovementComp* WTRBaseCharacterMovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = " Character | Movement")
	class ULedgeDetectionVaultingComponent* VaultingLedgeDetector;
private:
	void TryChangeSprintState();
	bool bIsSprintRequested = false;

	TArray<AInteractiveActor*> AvailableInteractiveActors;

};
