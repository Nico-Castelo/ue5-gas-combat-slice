// Fill out your copyright notice in the Description page of Project Settings.


#include "BladeWeaponTraceComponent.h"

#include "Blade.h"
#include "BladeCharacterBase.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/StaticMeshComponent.h"


UBladeWeaponTraceComponent::UBladeWeaponTraceComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
	
}
void UBladeWeaponTraceComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	const FVector Start = WeaponMesh->GetSocketLocation(TraceStartSocketName);
	const FVector End = WeaponMesh->GetSocketLocation(TraceEndSocketName);

	TArray<FHitResult> Hits;
	UKismetSystemLibrary::SphereTraceMulti(this, Start, End, TraceRadius,
	UEngineTypes::ConvertToTraceType(ECC_Weapon), false, { GetOwner() },
	EDrawDebugTrace::ForDuration, Hits, true, FLinearColor::Red, FLinearColor::Green, 2.0f);
	
	for (const FHitResult& Hit: Hits)
	{
		AActor* HitActor = Hit.GetActor();
		
		if (!HitActor || HitActors.Contains(HitActor)) continue;
		
		HitActors.Add(HitActor);
		
		UE_LOG(LogGame, Log, TEXT("Weapon hit: %s"), *HitActor->GetName());
	}
}

void UBladeWeaponTraceComponent::BeginPlay()
{
	Super::BeginPlay();
	
	ABladeCharacterBase* Character = Cast<ABladeCharacterBase>(GetOwner());

	if (!ensureMsgf(Character, TEXT("%s: el owner no es ABladeCharacterBase"), *GetName())) return;

	WeaponMesh = Character->GetWeaponMesh();
}

void UBladeWeaponTraceComponent::StartTrace()
{
	if (!ensure(WeaponMesh)) return;

	HitActors.Reset();
	SetComponentTickEnabled(true);
}

void UBladeWeaponTraceComponent::StopTrace()
{
	SetComponentTickEnabled(false);
}

