// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BladeGameplayAbility.generated.h"

class UAnimMontage;

UCLASS(Abstract)
class BLADE_API UBladeGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
	
	void PlayMontageAndEndOnCompletion(UAnimMontage* Montage, float Rate = 1.0f, float RootMotionScale = 1.0f, FName StartSection = NAME_None);

	UFUNCTION()
	virtual void OnMontageCompleted();

	UFUNCTION()
	virtual void OnMontageBlendOut();

	UFUNCTION()
	virtual void OnMontageCancelled();
};
