// Fill out your copyright notice in the Description page of Project Settings.


#include "BladeGameplayAbility_Attack.h"
#include "Blade.h"
#include "BladeGameplayTags.h"

UBladeGameplayAbility_Attack::UBladeGameplayAbility_Attack()
{
	FGameplayTagContainer Tags;
	Tags.AddTag(BladeGameplayTags::Ability_Attack);
	SetAssetTags(Tags);
	
	ActivationOwnedTags.AddTag(BladeGameplayTags::State_Attacking);
	ActivationBlockedTags.AddTag(BladeGameplayTags::State_Attacking);
	ActivationBlockedTags.AddTag(BladeGameplayTags::State_Evading);
}

void UBladeGameplayAbility_Attack::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}
	
	PlayMontageAndEndOnCompletion(AttackMontage, Rate, RootMotionScale);
	
	UE_LOG(LogGame, Log, TEXT("Attack Ability Activated"));
}
