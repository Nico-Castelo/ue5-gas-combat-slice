// Fill out your copyright notice in the Description page of Project Settings.


#include "BladeCharacterBase.h"

#include "AbilitySystemComponent.h"
#include "BladeWeaponTraceComponent.h"
#include "AbilitySystem/Attributes/BladeAttributeSet.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


ABladeCharacterBase::ABladeCharacterBase()
{
	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComp"));
	
	AttributeSet = CreateDefaultSubobject<UBladeAttributeSet>(TEXT("AttributeSet"));
	
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(GetMesh(), TEXT("weapon_r1Socket"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	TraceComponent = CreateDefaultSubobject<UBladeWeaponTraceComponent>(TEXT("TraceComp"));
}

void ABladeCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	ASC->InitAbilityActorInfo(this, this);
	
	ASC->GetGameplayAttributeValueChangeDelegate(UBladeAttributeSet::GetMoveSpeedAttribute())
	.AddUObject(this, &ABladeCharacterBase::OnMoveSpeedChanged);
	
	FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(DefaultAttributeEffect, 1.0f, ASC->MakeEffectContext());
	if (ensureMsgf(SpecHandle.IsValid(), TEXT("%s: GE_Init_Attributes not set in Blueprint"), *GetNameSafe(this)))
	{
		ASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
	
	GetCharacterMovement()->MaxWalkSpeed = AttributeSet->GetMoveSpeed();
	
	for (const TSubclassOf<UGameplayAbility>& AbilityClass : DefaultAbilities)
	{
		ASC->GiveAbility(FGameplayAbilitySpec(AbilityClass));
	}
}

void ABladeCharacterBase::OnMoveSpeedChanged(const FOnAttributeChangeData& Data)
{
	GetCharacterMovement()->MaxWalkSpeed = Data.NewValue;
}
