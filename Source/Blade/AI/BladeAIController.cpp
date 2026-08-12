// Fill out your copyright notice in the Description page of Project Settings.


#include "BladeAIController.h"

#include "BladeGameTypes.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"


ABladeAIController::ABladeAIController()
{
	
}

void ABladeAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	if (!ensureMsgf(BehaviourTree, TEXT("BehaviourTree not assigned to %s"), *GetNameSafe(this))) return;
		
	RunBehaviorTree(BehaviourTree);
	
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	check(PlayerPawn);
	
	GetBlackboardComponent()->SetValueAsObject(NAME_TargetActor, PlayerPawn);
	
	SetFocus(PlayerPawn);
}

