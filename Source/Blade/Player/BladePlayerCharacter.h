// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/BladeCharacterBase.h"
#include "BladePlayerCharacter.generated.h"

struct FInputActionValue;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class BLADE_API ABladePlayerCharacter : public ABladeCharacterBase
{
	GENERATED_BODY()

public:
	
	ABladePlayerCharacter();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
protected:
	
	void Move(const FInputActionValue& InValue);
	
	void Look(const FInputActionValue& InValue);
	
	void Attack();
	
	void Evade();
	
	void Sprint();
	
	void StopSprinting();
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> Input_Move;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> Input_Look;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> Input_Jump;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> Input_Evade;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> Input_Attack;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> Input_Sprint;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<UCameraComponent> CameraComponent;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "Speed")
	float SprintSpeed = 1000.0f;

	float CachedWalkSpeed = 0.0f;

	bool bIsSprinting = false;
};
