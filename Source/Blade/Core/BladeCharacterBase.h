// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "BladeCharacterBase.generated.h"

class UBladeWeaponTraceComponent;
class UGameplayAbility;
class UBladeAttributeSet;
class UAbilitySystemComponent;

UCLASS()
class BLADE_API ABladeCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	ABladeCharacterBase();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return ASC; }
	
	virtual void PossessedBy(AController* NewController) override;
	
protected:
	
	UPROPERTY(VisibleAnywhere, Category = "Ability System")
	TObjectPtr<UAbilitySystemComponent> ASC;
	
	UPROPERTY(VisibleAnywhere, Category = "Ability System")
	TObjectPtr<UBladeAttributeSet> AttributeSet;
	
	UPROPERTY(EditDefaultsOnly, Category = "Ability System")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;
	
	UPROPERTY(VisibleAnywhere, Category = "Combat")
	TObjectPtr<UStaticMeshComponent> WeaponMesh;
	
	UPROPERTY(VisibleAnywhere, Category = "Combat")
	TObjectPtr<UBladeWeaponTraceComponent> TraceComponent;
	
public:
	
	UStaticMeshComponent* GetWeaponMesh() { return WeaponMesh; }
};
