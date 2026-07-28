// Fill out your copyright notice in the Description page of Project Settings.


#include "BladeGameplayAbility_Evade.h"

#include "Blade.h"
#include "BladeGameplayTags.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"

UBladeGameplayAbility_Evade::UBladeGameplayAbility_Evade()
{
	FGameplayTagContainer Tags;
	Tags.AddTag(BladeGameplayTags::Ability_Evade);
	SetAssetTags(Tags);

	ActivationOwnedTags.AddTag(BladeGameplayTags::State_Evading);
	ActivationBlockedTags.AddTag(BladeGameplayTags::State_Evading);
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

	UAbilityTask_PlayMontageAndWait* MontageTask = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(
		this,
		NAME_None,
		EvadeMontage,
		1.0f,
		NAME_None,
		true,
		RootMotionScale);

	MontageTask->OnCompleted.AddDynamic(this, &UBladeGameplayAbility_Evade::OnMontageCompleted);
	MontageTask->OnInterrupted.AddDynamic(this, &UBladeGameplayAbility_Evade::OnMontageCancelled);
	MontageTask->OnCancelled.AddDynamic(this, &UBladeGameplayAbility_Evade::OnMontageCancelled);

	MontageTask->ReadyForActivation();

	UE_LOG(LogGame, Log, TEXT("Evade Ability Activated"));
}

void UBladeGameplayAbility_Evade::OnMontageCompleted()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}

void UBladeGameplayAbility_Evade::OnMontageCancelled()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
}
