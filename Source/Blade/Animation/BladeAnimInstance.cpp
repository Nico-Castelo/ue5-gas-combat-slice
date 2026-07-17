// Fill out your copyright notice in the Description page of Project Settings.


#include "BladeAnimInstance.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBladeAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if (OwnerCharacter)
	{
		OwnerMovementComponent = OwnerCharacter->GetCharacterMovement();
	}
}

void UBladeAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	
	if (!OwnerMovementComponent) return;
	
	GroundSpeed = OwnerMovementComponent->Velocity.Size2D();
	bIsFalling = OwnerMovementComponent->IsFalling();
}
