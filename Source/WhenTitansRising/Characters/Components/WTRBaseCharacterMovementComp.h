// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "WTRBaseCharacterMovementComp.generated.h"

UENUM(BlueprintType)
enum class ECustomMovementMode : uint8
{
	CMOVE_None = 0 UMETA(DisplayName = "None"),
	CMOVE_Ladder UMETA(DisplayName = "Ladder"),
	CMOVE_Max UMETA(Hidden)
};

/**
 * 
 */
UCLASS()
class WHENTITANSRISING_API UWTRBaseCharacterMovementComp : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	FORCEINLINE bool IsSprinting() { return bIsSprinting; }

	virtual float GetMaxSpeed() const override;

	void StartSprint();
	void StopSprint();

	void AttachToLadder(const class ALadder* Ladder);
	void DetachFromLadder();
	bool IsOnLadder() const;

protected:
	
	virtual void OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character movement", meta = (ClampMin = 0, UIMin = 0))
	FRotator BaseRotationRate = FRotator(0.0f, 500.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character movement | Swimming", meta = (ClampMin = 0, UIMin = 0))
	FRotator SwimmingRotationRate = FRotator(0.0f, 300.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character movement | Swimming", meta = (ClampMin = 0, UIMin = 0))
	float SwimmingCapsuleRadius = 60.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character movement | Swimming", meta = (ClampMin = 0, UIMin = 0))
	float SwimmingCapsuleHalfHeight = 60.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character movement | Swimming", meta = (ClampMin = 0, UIMin = 0))
	float SwimmingSpeed = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character movement | Sprint", meta = (ClampMin = 0.0f, UIMin = 0.0f))
	float SprintSpeed = 1200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character movement | Ladder")
	float ClimbingOnLadderSpeed = 200.0f;

	virtual void PhysCustom(float DeltaTime, int32 Iterations) override;

private:
	bool bIsSprinting;

	const ALadder* CurrentLadder = nullptr;
};
