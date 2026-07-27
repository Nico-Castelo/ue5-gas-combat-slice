// Fill out your copyright notice in the Description page of Project Settings.


#include "BladeGameplayAbility_Roll.h"

#include "Blade.h"
#include "BladeGameplayTags.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"
#include "GameFramework/RootMotionSource.h"

UBladeGameplayAbility_Roll::UBladeGameplayAbility_Roll()
{
	FGameplayTagContainer Tags;
	Tags.AddTag(BladeGameplayTags::Ability_Roll);
	SetAssetTags(Tags);
	
	ActivationOwnedTags.AddTag(BladeGameplayTags::State_Rolling);
	ActivationBlockedTags .AddTag(BladeGameplayTags::State_Rolling);
}

void UBladeGameplayAbility_Roll::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}
	
	UAbilityTask_PlayMontageAndWait* MontageTask = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(
		this,
		NAME_None,
		RollMontage,
		1.0f,
		NAME_None,
		true,
		RootMotionScale);
	
	MontageTask->OnCompleted.AddDynamic(this, &UBladeGameplayAbility_Roll::OnMontageCompleted);
	MontageTask->OnInterrupted.AddDynamic(this, &UBladeGameplayAbility_Roll::OnMontageCancelled);
	MontageTask->OnCancelled.AddDynamic(this, &UBladeGameplayAbility_Roll::OnMontageCancelled);
	
	MontageTask->ReadyForActivation();
	
	UE_LOG(LogGame, Log, TEXT("Roll Ability Activated"));
}

void UBladeGameplayAbility_Roll::OnMontageCompleted()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}

void UBladeGameplayAbility_Roll::OnMontageCancelled()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
}
