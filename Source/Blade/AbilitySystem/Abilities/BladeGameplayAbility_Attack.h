// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BladeGameplayAbility.h"
#include "BladeGameplayAbility_Attack.generated.h"

UCLASS()
class BLADE_API UBladeGameplayAbility_Attack : public UBladeGameplayAbility
{
	GENERATED_BODY()
	
public:
	
	UBladeGameplayAbility_Attack();
	
protected:
	
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	
	UFUNCTION()
	void OnRecoveryStarted();
	
	UPROPERTY(EditDefaultsOnly, Category = "Attack")
	TObjectPtr<UAnimMontage> AttackMontage;
	
	UPROPERTY(EditDefaultsOnly, Category = "Attack", meta = (ClampMin = "0.0"))
	float RootMotionScale = 1.0f;
	
	UPROPERTY(EditDefaultsOnly, Category = "Attack", meta = (ClampMin = "0.0"))
	float Rate = 1.6f;
};
