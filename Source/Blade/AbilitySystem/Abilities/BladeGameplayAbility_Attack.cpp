// Fill out your copyright notice in the Description page of Project Settings.


#include "BladeGameplayAbility_Attack.h"

#include "AbilitySystemComponent.h"
#include "Blade.h"
#include "BladeGameplayTags.h"
#include "Abilities/Tasks/AbilityTask_WaitGameplayEvent.h"

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
	
	GetAbilitySystemComponentFromActorInfo()->AddLooseGameplayTag(BladeGameplayTags::State_Attacking_Committed);

	UAbilityTask_WaitGameplayEvent* WaitRecover = UAbilityTask_WaitGameplayEvent::WaitGameplayEvent(
		this, BladeGameplayTags::Event_Montage_Recover, nullptr, true);
	WaitRecover->EventReceived.AddDynamic(this, &UBladeGameplayAbility_Attack::OnRecoveryStarted);
	WaitRecover->ReadyForActivation();
	
	PlayMontageAndEndOnCompletion(AttackMontage, Rate, RootMotionScale);
	
	UE_LOG(LogGame, Log, TEXT("Attack Ability Activated"));
}

void UBladeGameplayAbility_Attack::EndAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility, bool bWasCancelled)
{
	UAbilitySystemComponent* ASC = GetAbilitySystemComponentFromActorInfo();
	if (ASC && ASC->HasMatchingGameplayTag(BladeGameplayTags::State_Attacking_Committed))
	{
		ASC->RemoveLooseGameplayTag(BladeGameplayTags::State_Attacking_Committed);
	}	

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UBladeGameplayAbility_Attack::OnRecoveryStarted()
{
	GetAbilitySystemComponentFromActorInfo()->RemoveLooseGameplayTag(BladeGameplayTags::State_Attacking_Committed);
}
