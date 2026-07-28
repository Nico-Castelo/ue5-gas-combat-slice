// Fill out your copyright notice in the Description page of Project Settings.


#include "BladeGameplayAbility.h"

#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"

void UBladeGameplayAbility::PlayMontageAndEndOnCompletion(UAnimMontage* Montage, float Rate, float RootMotionScale)
{
	UAbilityTask_PlayMontageAndWait* MontageTask = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(
		this,
		NAME_None,
		Montage,
		Rate,
		NAME_None,
		true,
		RootMotionScale
	);

	MontageTask->OnCompleted.AddDynamic(this, &UBladeGameplayAbility::OnMontageCompleted);
	MontageTask->OnInterrupted.AddDynamic(this, &UBladeGameplayAbility::OnMontageCancelled);
	MontageTask->OnCancelled.AddDynamic(this, &UBladeGameplayAbility::OnMontageCancelled);

	MontageTask->ReadyForActivation();
}

void UBladeGameplayAbility::OnMontageCompleted()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}

void UBladeGameplayAbility::OnMontageCancelled()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
}
