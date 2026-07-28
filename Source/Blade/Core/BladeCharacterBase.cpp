// Fill out your copyright notice in the Description page of Project Settings.


#include "BladeCharacterBase.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/Attributes/BladeAttributeSet.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"


ABladeCharacterBase::ABladeCharacterBase()
{
	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComp"));
	
	AttributeSet = CreateDefaultSubobject<UBladeAttributeSet>(TEXT("AttributeSet"));
	
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(GetMesh(), TEXT("weapon_r1Socket"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
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
