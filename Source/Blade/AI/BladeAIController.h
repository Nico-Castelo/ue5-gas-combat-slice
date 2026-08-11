// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "BladeAIController.generated.h"

class UBehaviorTree;

UCLASS()
class BLADE_API ABladeAIController : public AAIController
{
	GENERATED_BODY()

public:
	ABladeAIController();

protected:
	
	virtual void OnPossess(APawn* InPawn) override;
	
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviourTree;
	
	FName TargetActor = FName("TargetActor");
};
