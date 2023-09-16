// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LedgeDetectionVaultingComponent.generated.h"

USTRUCT(BlueprintType)
struct FLedgeDesciption
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LedgeDescription")
	FVector Location;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LedgeDescription")
	FRotator Rotation;


};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WHENTITANSRISING_API ULedgeDetectionVaultingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	bool DetectLedge(OUT FLedgeDesciption& LedgeDescription);

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Detection settings", meta = (UIMin = 0, ClampMin = 0))
	float MinimumVaultingHeight = 40.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Detection settings", meta = (UIMin = 0, ClampMin = 0))
	float MaximumVaultingHeight = 80.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Detection settings", meta = (UIMin = 0, ClampMin = 0))
	float ForwardCheckDistance = 100.0f;

private:
	TWeakObjectPtr<class ACharacter> CharacterOwner;
};
