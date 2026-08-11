// Fill out your copyright notice in the Description page of Project Settings.


#include "BladeAttributeSet.h"

#include "GameplayEffectExtension.h"

UBladeAttributeSet::UBladeAttributeSet()
{
	
}

void UBladeAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}
	
	if (Data.EvaluatedData.Attribute == GetPostureAttribute())
	{
		SetPosture(FMath::Clamp(GetPosture(), 0.0f, GetMaxPosture()));
	}
}
