// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BladeGameplayAbility_Evade.generated.h"

class UAnimMontage;

UCLASS()
class BLADE_API UBladeGameplayAbility_Evade : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UBladeGameplayAbility_Evade();

protected:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditDefaultsOnly, Category = "Evade")
	TObjectPtr<UAnimMontage> EvadeMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Evade", meta = (ClampMin = "0.0"))
	float RootMotionScale = 1.25f;

	UFUNCTION()
	void OnMontageCompleted();

	UFUNCTION()
	void OnMontageCancelled();
};
