// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Interactive/InteractiveActor.h"
#include "Ladder.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class WHENTITANSRISING_API ALadder : public AInteractiveActor
{
	GENERATED_BODY()
	
public:
	ALadder();

	virtual void OnConstruction(const FTransform& Transform) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ladder params")
	float LadderHeight = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ladder params")
	float LadderWidth = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ladder params")
	float StepInterval = 25.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ladder params")
	float BottomStepOddset = 25.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* RightRailMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* LeftRailMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UInstancedStaticMeshComponent* StepsMeshComponent;

	class UBoxComponent* GetLadderInteractionBox() const;
};
