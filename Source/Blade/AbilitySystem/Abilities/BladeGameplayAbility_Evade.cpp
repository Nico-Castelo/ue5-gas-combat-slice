// Fill out your copyright notice in the Description page of Project Settings.

#include "BladeGameplayAbility_Evade.h"
#include "Blade.h"
#include "BladeGameplayTags.h"
#include "Abilities/Tasks/AbilityTask_WaitGameplayEvent.h"
#include "Animation/AnimInstance.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UBladeGameplayAbility_Evade::UBladeGameplayAbility_Evade()
{
	FGameplayTagContainer Tags;
	Tags.AddTag(BladeGameplayTags::Ability_Evade);
	SetAssetTags(Tags);

	ActivationOwnedTags.AddTag(BladeGameplayTags::State_Evading);
	ActivationBlockedTags.AddTag(BladeGameplayTags::State_Evading);
	ActivationBlockedTags.AddTag(BladeGameplayTags::State_Attacking_Committed);
	ActivationBlockedTags.AddTag(BladeGameplayTags::State_HitReacting);
	
	CancelAbilitiesWithTag.AddTag(BladeGameplayTags::Ability_Block);
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
	
	UAbilityTask_WaitGameplayEvent* WaitRecover = UAbilityTask_WaitGameplayEvent::WaitGameplayEvent(
		this, BladeGameplayTags::Event_Montage_Recover, nullptr, true);
	WaitRecover->EventReceived.AddDynamic(this, &UBladeGameplayAbility_Evade::OnRecoveryStarted);
	WaitRecover->ReadyForActivation();

	PlayMontageAndEndOnCompletion(EvadeMontage, Rate, RootMotionScale);

	UE_LOG(LogGame, Verbose, TEXT("Evade Ability Activated"));
}

void UBladeGameplayAbility_Evade::OnMontageBlendOut()
{
	Super::OnMontageBlendOut();
	
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}

void UBladeGameplayAbility_Evade::OnRecoveryStarted(FGameplayEventData Payload)
{
	const UCharacterMovementComponent* MovementComponent = Cast<UCharacterMovementComponent>(CurrentActorInfo->MovementComponent.Get());
	if (!MovementComponent) return;

	FVector MoveInput = MovementComponent->GetPendingInputVector();
	if (MoveInput.IsNearlyZero())
	{
		MoveInput = MovementComponent->GetLastInputVector();
	}
	if (MoveInput.IsNearlyZero()) return;

	const ACharacter* Character = Cast<ACharacter>(GetAvatarActorFromActorInfo());
	if (!Character) return;
	
	UAnimInstance* AnimInstance = Character->GetMesh()->GetAnimInstance();
	if (!ensure(AnimInstance)) return;

	UAnimMontage* MontageToStop = GetCurrentMontage();
	if (!MontageToStop)
	{
		MontageToStop = EvadeMontage;
	}
	
	if (!MontageToStop) return;

	AnimInstance->Montage_Stop(RecoveryCancelBlendOut, MontageToStop);
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}
