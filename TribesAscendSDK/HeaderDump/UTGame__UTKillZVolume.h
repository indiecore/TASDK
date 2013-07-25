#pragma once
#include "Engine__PhysicsVolume.h"
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTKillZVolume." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTKillZVolume : public PhysicsVolume
	{
	public:
		ADD_OBJECT(ScriptClass, KillZDamageType)
		// Here lies the not-yet-implemented method 'ActorEnteredVolume'
		// Here lies the not-yet-implemented method 'PawnEnteredVolume'
		// Here lies the not-yet-implemented method 'Touch'
		// Here lies the not-yet-implemented method 'KillActor'
	};
}
#undef ADD_OBJECT
