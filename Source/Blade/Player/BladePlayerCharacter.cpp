// Fill out your copyright notice in the Description page of Project Settings.


#include "BladePlayerCharacter.h"

#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ABladePlayerCharacter::ABladePlayerCharacter()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void ABladePlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* EnhancedInput = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	
	EnhancedInput->BindAction(Input_Move, ETriggerEvent::Triggered, this, &ABladePlayerCharacter::Move);
	EnhancedInput->BindAction(Input_Look, ETriggerEvent::Triggered, this, &ABladePlayerCharacter::Look);
	
	EnhancedInput->BindAction(Input_Jump, ETriggerEvent::Started, this, &ABladePlayerCharacter::Jump);
	EnhancedInput->BindAction(Input_Jump, ETriggerEvent::Completed, this, &ABladePlayerCharacter::StopJumping);
}

void ABladePlayerCharacter::Move(const FInputActionValue& InValue)
{
	const FVector2D InputValue = InValue.Get<FVector2D>();
	
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	const FVector ForwardDirection = ControlRot.Vector();
	const FVector RightDirection = ControlRot.RotateVector(FVector::RightVector);

	// Forward / Back
	AddMovementInput(ForwardDirection, InputValue.Y);

	// Right / Left
	AddMovementInput(RightDirection, InputValue.X);
}

void ABladePlayerCharacter::Look(const FInputActionValue& InValue)
{
	const FVector2D InputValue = InValue.Get<FVector2D>();
	
	AddControllerPitchInput(InputValue.Y);
	AddControllerYawInput(InputValue.X);
}