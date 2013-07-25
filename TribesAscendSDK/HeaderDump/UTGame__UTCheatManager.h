#pragma once
#include "Engine__CheatManager.h"
#include "Engine__SpeechRecognition.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCheatManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCheatManager : public CheatManager
	{
	public:
		ADD_OBJECT(SpeechRecognition, RecogObject)
		ADD_OBJECT(ScriptClass, LMC)
		// Here lies the not-yet-implemented method 'ViewFlag'
		// Here lies the not-yet-implemented method 'Glow'
		// Here lies the not-yet-implemented method 'LM'
		// Here lies the not-yet-implemented method 'LMS'
		// Here lies the not-yet-implemented method 'SummonV'
		// Here lies the not-yet-implemented method 'AllWeapons'
		// Here lies the not-yet-implemented method 'DoubleUp'
		// Here lies the not-yet-implemented method 'ChainGun'
		// Here lies the not-yet-implemented method 'AllAmmo'
		// Here lies the not-yet-implemented method 'Invisible'
		// Here lies the not-yet-implemented method 'FreeCamera'
		// Here lies the not-yet-implemented method 'ViewBot'
		// Here lies the not-yet-implemented method 'KillBadGuys'
		// Here lies the not-yet-implemented method 'RBGrav'
		// Here lies the not-yet-implemented method 'SuicideBy'
		// Here lies the not-yet-implemented method 'EditWeapon'
		// Here lies the not-yet-implemented method 'KillOtherBots'
		// Here lies the not-yet-implemented method 'SpawnABloodDecal'
		// Here lies the not-yet-implemented method 'LeaveADecal'
		// Here lies the not-yet-implemented method 'TiltIt'
		// Here lies the not-yet-implemented method 'ShowStickBindings'
		// Here lies the not-yet-implemented method 'SetStickBind'
		// Here lies the not-yet-implemented method 'KillAll'
		// Here lies the not-yet-implemented method 'KillAllPawns'
	};
}
#undef ADD_OBJECT
