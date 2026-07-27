// Fill out your copyright notice in the Description page of Project Settings.


#include "BladeCharacterBase.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/Attributes/BladeAttributeSet.h"


ABladeCharacterBase::ABladeCharacterBase()
{
	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComp"));
	
	AttributeSet = CreateDefaultSubobject<UBladeAttributeSet>(TEXT("AttributeSet"));
}

void ABladeCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	ASC->InitAbilityActorInfo(this, this);
	
	for (const TSubclassOf<UGameplayAbility>& AbilityClass : DefaultAbilities)
	{
		ASC->GiveAbility(FGameplayAbilitySpec(AbilityClass));
	}
}
