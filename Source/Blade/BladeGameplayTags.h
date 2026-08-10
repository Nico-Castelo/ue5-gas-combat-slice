#pragma once

#include "NativeGameplayTags.h"

namespace BladeGameplayTags
{	
	
	// Ability tags
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Attack);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Evade);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_HitReact);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Block);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Sprint);
	
	// State tags
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(State_Attacking);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(State_Attacking_Committed);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(State_Evading);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(State_HitReacting);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(State_Blocking);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(State_Sprinting);
	
	// Event tags
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Event_Montage_Recover);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Event_Montage_HitWindow_Begin);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Event_Montage_HitWindow_End);
	
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Event_Combat_HitDealt);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Event_Combat_HitReceived);
}
