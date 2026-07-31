#include "BladeGameplayTags.h"

namespace BladeGameplayTags
{
	UE_DEFINE_GAMEPLAY_TAG(Ability_Attack, "Ability.Attack");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Evade, "Ability.Evade");
	UE_DEFINE_GAMEPLAY_TAG(Ability_HitReact, "Ability.HitReact");
	
	
	UE_DEFINE_GAMEPLAY_TAG(State_Attacking, "State.Attacking");
	UE_DEFINE_GAMEPLAY_TAG(State_Evading, "State.Evading");
	UE_DEFINE_GAMEPLAY_TAG(State_Attacking_Committed, "State.Attacking.Committed");
	UE_DEFINE_GAMEPLAY_TAG(State_HitReacting, "State.HitReacting");
	
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Event_Montage_Recover, "Event.Montage.Recover", "Sent from the attack montage when recovery starts. The attack ability clears the committed state, opening the cancel window");
	UE_DEFINE_GAMEPLAY_TAG(Event_Montage_HitWindow_Begin, "Event.Montage.HitWindow.Begin");
	UE_DEFINE_GAMEPLAY_TAG(Event_Montage_HitWindow_End, "Event.Montage.HitWindow.End");
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Event_Combat_HitDealt, "Event.Combat.HitDealt", "Sent to the attacker's own ASC when their weapon trace confirms a hit. Consumed by the attack ability to apply damage.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Event_Combat_HitReceived, "Event.Combat.HitReceived", "Sent to the victim's ASC when a hit lands on them. Triggers the hit react ability.");
}
