// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BladeGameplayAbility_Roll.generated.h"

class UAnimMontage;

UCLASS()
class BLADE_API UBladeGameplayAbility_Roll : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	
	UBladeGameplayAbility_Roll();
	
protected:
	
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Roll")
	TObjectPtr<UAnimMontage> RollMontage;
	
	UPROPERTY(EditDefaultsOnly, Category = "Roll", meta = (ClampMin = "0.0"))
	float RootMotionScale = 1.25f;
	
	UFUNCTION()
	void OnMontageCompleted();
	
	UFUNCTION()
	void OnMontageCancelled();
};
