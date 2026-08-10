// Fill out your copyright notice in the Description page of Project Settings.


#include "BladeGameplayAbility_Block.h"
#include "BladeGameplayTags.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UBladeGameplayAbility_Block::UBladeGameplayAbility_Block()
{
	FGameplayTagContainer Tags;
	Tags.AddTag(BladeGameplayTags::Ability_Block);
	SetAssetTags(Tags);
	
	ActivationOwnedTags.AddTag(BladeGameplayTags::State_Blocking);
}

void UBladeGameplayAbility_Block::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	if (const ACharacter* Avatar = Cast<ACharacter>(GetAvatarActorFromActorInfo()))
	{
		UCharacterMovementComponent* MoveComp = Avatar->GetCharacterMovement();
		CachedWalkSpeed = MoveComp->MaxWalkSpeed;
		MoveComp->MaxWalkSpeed = BlockWalkSpeed;
	}
}

void UBladeGameplayAbility_Block::EndAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility, bool bWasCancelled)
{
	// CachedWalkSpeed == 0 means the cap was never applied
	if (CachedWalkSpeed > 0.0f)
	{
		if (const ACharacter* Avatar = Cast<ACharacter>(GetAvatarActorFromActorInfo()))
		{
			Avatar->GetCharacterMovement()->MaxWalkSpeed = CachedWalkSpeed;
		}
	}

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
