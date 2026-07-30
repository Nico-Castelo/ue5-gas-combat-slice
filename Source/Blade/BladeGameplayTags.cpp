#include "BladeGameplayTags.h"

namespace BladeGameplayTags
{
	UE_DEFINE_GAMEPLAY_TAG(Ability_Attack, "Ability.Attack");
	UE_DEFINE_GAMEPLAY_TAG(State_Attacking, "State.Attacking");
	
	UE_DEFINE_GAMEPLAY_TAG(Ability_Evade, "Ability.Evade");
	UE_DEFINE_GAMEPLAY_TAG(State_Evading, "State.Evading");
	
	UE_DEFINE_GAMEPLAY_TAG(Event_Montage_Recover, "Event.Montage.Recover");
	UE_DEFINE_GAMEPLAY_TAG(State_Attacking_Committed, "State.Attacking.Committed");
	
	UE_DEFINE_GAMEPLAY_TAG(Event_Montage_HitWindow_Begin, "Event.Montage.HitWindow.Begin");
	UE_DEFINE_GAMEPLAY_TAG(Event_Montage_HitWindow_End, "Event.Montage.HitWindow.End");
}
