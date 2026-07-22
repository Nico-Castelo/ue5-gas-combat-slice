// Fill out your copyright notice in the Description page of Project Settings.


#include "BladeCharacterBase.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/BladeAttributeSet.h"


ABladeCharacterBase::ABladeCharacterBase()
{
	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComp"));
	
	AttributeSet = CreateDefaultSubobject<UBladeAttributeSet>(TEXT("AttributeSet"));
}

void ABladeCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	ASC->InitAbilityActorInfo(this, this);
}
