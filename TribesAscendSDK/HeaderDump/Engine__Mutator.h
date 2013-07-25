#pragma once
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__Info.h"
#include "Engine__NavigationPoint.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#include "Engine__Actor.h"
#include "Engine__Vehicle.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Mutator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Mutator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Mutator : public Info
	{
	public:
		ADD_OBJECT(Mutator, NextMutator)
		ADD_VAR(::BoolProperty, bUserAdded, 0x1)
		// Here lies the not-yet-implemented method 'PreventDeath'
		// Here lies the not-yet-implemented method 'CheckRelevance'
		// Here lies the not-yet-implemented method 'OverridePickupQuery'
		// Here lies the not-yet-implemented method 'HandleRestartGame'
		// Here lies the not-yet-implemented method 'CheckEndGame'
		// Here lies the not-yet-implemented method 'FindPlayerStart'
		// Here lies the not-yet-implemented method 'CanLeaveVehicle'
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'MutatorIsAllowed'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'Mutate'
		// Here lies the not-yet-implemented method 'ModifyLogin'
		// Here lies the not-yet-implemented method 'ModifyPlayer'
		// Here lies the not-yet-implemented method 'AddMutator'
		// Here lies the not-yet-implemented method 'AlwaysKeep'
		// Here lies the not-yet-implemented method 'IsRelevant'
		// Here lies the not-yet-implemented method 'CheckReplacement'
		// Here lies the not-yet-implemented method 'NotifyLogout'
		// Here lies the not-yet-implemented method 'NotifyLogin'
		// Here lies the not-yet-implemented method 'DriverEnteredVehicle'
		// Here lies the not-yet-implemented method 'DriverLeftVehicle'
		// Here lies the not-yet-implemented method 'InitMutator'
		// Here lies the not-yet-implemented method 'GetSeamlessTravelActorList'
		// Here lies the not-yet-implemented method 'ScoreObjective'
		// Here lies the not-yet-implemented method 'ScoreKill'
		// Here lies the not-yet-implemented method 'NetDamage'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
