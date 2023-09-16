// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Components/LedgeDetectionVaultingComponent.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "WTR_Types.h"

void ULedgeDetectionVaultingComponent::BeginPlay()
{
	Super::BeginPlay();
	checkf(GetOwner()->IsA<ACharacter>(), TEXT("ULedgeDetectionVaultingComponent::BeginPlay() only ACharacter can use Ledge"));
	CharacterOwner = StaticCast<ACharacter*>(GetOwner());
}

bool ULedgeDetectionVaultingComponent::DetectLedge(OUT FLedgeDesciption& LedgeDescription)
{
	UCapsuleComponent* CapsuleComponent = CharacterOwner->GetCapsuleComponent();

	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = true;
	QueryParams.AddIgnoredActor(GetOwner());

	float BottomZOffset = 2.0f;
	FVector CharacterBottom = CharacterOwner->GetActorLocation() - (CapsuleComponent->GetScaledCapsuleHalfHeight() - BottomZOffset) * FVector::UpVector;

	//1. ForwardCheck
	float ForwardCheckCapsuleRadius = CapsuleComponent->GetScaledCapsuleRadius();
	float ForwardCheckCapsuleHalfHeight = (MaximumVaultingHeight - MinimumVaultingHeight) * 0.5;

	FCollisionShape ForwardCapsuleShape = FCollisionShape::MakeCapsule(ForwardCheckCapsuleRadius, ForwardCheckCapsuleHalfHeight);
	FVector ForwardStartLocation = CharacterBottom + (MinimumVaultingHeight + ForwardCheckCapsuleHalfHeight) * FVector::UpVector;
	FVector ForwardEndLocation = ForwardStartLocation + CharacterOwner->GetActorForwardVector() * ForwardCheckDistance;

	FHitResult ForwardCheckHitResult;

	if (!GetWorld()->SweepSingleByChannel(ForwardCheckHitResult, ForwardStartLocation, ForwardEndLocation, FQuat::Identity, ECC_Climbing, ForwardCapsuleShape, QueryParams))
	{
		return false;
	}

	//2. Downward check
	FHitResult DownwardCheckHitResult;
	float DownwardSphereCheckRadius = CapsuleComponent->GetScaledCapsuleRadius();
	FCollisionShape DownwardSphereShape = FCollisionShape::MakeSphere(DownwardSphereCheckRadius);

	float DownwardDepthOffset = 10.0f;
	FVector DownwardTraceStartLocation = ForwardCheckHitResult.ImpactPoint - ForwardCheckHitResult.ImpactNormal * DownwardDepthOffset;
	DownwardTraceStartLocation.Z = CharacterBottom.Z + MaximumVaultingHeight + DownwardSphereCheckRadius;
	FVector DownwardTraceEndLocation(DownwardTraceStartLocation.X, DownwardTraceStartLocation.Y, CharacterBottom.Z);

	if (!GetWorld()->SweepSingleByChannel(DownwardCheckHitResult, DownwardTraceStartLocation, DownwardTraceEndLocation, FQuat::Identity, ECC_Climbing, DownwardSphereShape, QueryParams))
	{
		return false;
	}

	//3. Overlap check

	FCollisionShape OverlapCapsuleShape = FCollisionShape::MakeCapsule(CapsuleComponent->GetScaledCapsuleRadius(), CapsuleComponent->GetScaledCapsuleHalfHeight());
	FVector OverlapLocation = DownwardCheckHitResult.ImpactPoint + CapsuleComponent->GetScaledCapsuleHalfHeight() * FVector::UpVector;

	if (GetWorld()->OverlapAnyTestByProfile(OverlapLocation, FQuat::Identity, FName("Pawn"), OverlapCapsuleShape, QueryParams))
	{
		return false;
	}

	LedgeDescription.Location = DownwardCheckHitResult.ImpactPoint;
	LedgeDescription.Rotation = (ForwardCheckHitResult.ImpactNormal * FVector(-1.0, -1.0f, 0.0f)).ToOrientationRotator();

	return true;
}

