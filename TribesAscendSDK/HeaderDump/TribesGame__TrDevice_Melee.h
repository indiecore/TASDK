#pragma once
#include "TribesGame__TrDevice_AutoFire.h"
#include "TribesGame__TrPawn.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_Melee." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_Melee : public TrDevice_AutoFire
	{
	public:
		ADD_OBJECT(AnimNodeSequence, FiringAnimSeqNode)
		// Here lies the not-yet-implemented method 'OwningClientPlayHit'
		// Here lies the not-yet-implemented method 'PlayFireAnimation'
		// Here lies the not-yet-implemented method 'CalcAmountToLoad'
		// Here lies the not-yet-implemented method 'HasAmmo'
		// Here lies the not-yet-implemented method 'GetBuildUpTime'
		// Here lies the not-yet-implemented method 'FireAmmunition'
		// Here lies the not-yet-implemented method 'ModifyInstantHitDamage'
		// Here lies the not-yet-implemented method 'AttemptFlagFumble'
	};
}
#undef ADD_OBJECT
