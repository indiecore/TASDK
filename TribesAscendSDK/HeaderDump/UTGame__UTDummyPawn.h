#pragma once
#include "Engine__SoundCue.h"
#include "UTGame__UTPawn.h"
#include "UTGame__UTSeqAct_DummyWeaponFire.h"
#include "Engine__Weapon.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTDummyPawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTDummyPawn : public UTPawn
	{
	public:
		ADD_OBJECT(UTSeqAct_DummyWeaponFire, FireAction)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'WeaponFired'
		// Here lies the not-yet-implemented method 'SetPawnAmbientSound'
		// Here lies the not-yet-implemented method 'SetWeaponAmbientSound'
		// Here lies the not-yet-implemented method 'GetAdjustedAimFor'
		// Here lies the not-yet-implemented method 'WeaponAttachmentChanged'
		// Here lies the not-yet-implemented method 'GetWeaponStartTraceLocation'
		// Here lies the not-yet-implemented method 'GetPawnViewLocation'
		// Here lies the not-yet-implemented method 'Tick'
	};
}
#undef ADD_OBJECT
