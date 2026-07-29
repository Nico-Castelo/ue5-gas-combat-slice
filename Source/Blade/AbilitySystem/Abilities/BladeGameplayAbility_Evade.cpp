// Fill out your copyright notice in the Description page of Project Settings.

#include "BladeGameplayAbility_Evade.h"
#include "Blade.h"
#include "BladeGameplayTags.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UBladeGameplayAbility_Evade::UBladeGameplayAbility_Evade()
{
	FGameplayTagContainer Tags;
	Tags.AddTag(BladeGameplayTags::Ability_Evade);
	SetAssetTags(Tags);

	ActivationOwnedTags.AddTag(BladeGameplayTags::State_Evading);
	ActivationBlockedTags.AddTag(BladeGameplayTags::State_Evading);
	ActivationBlockedTags.AddTag(BladeGameplayTags::State_Attacking);
}

void UBladeGameplayAbility_Evade::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	PlayMontageAndEndOnCompletion(EvadeMontage, Rate, RootMotionScale);

	UE_LOG(LogGame, Log, TEXT("Evade Ability Activated"));
}
