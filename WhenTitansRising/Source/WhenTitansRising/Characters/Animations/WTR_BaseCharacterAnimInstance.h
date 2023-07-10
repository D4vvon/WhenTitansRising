// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "WTR_BaseCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class WHENTITANSRISING_API UWTR_BaseCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeBeginPlay() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterAnimation")
	float Speed = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterAnimation")
	bool bIsFalling = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterAnimation")
	bool bIsCrouch = false;


private:
	TWeakObjectPtr<class AWTR_BaseCharacter> BaseCharacter;
};
