#pragma once
#include "Engine__AIController.h"
#include "TribesGame__TrPlayerController.h"
#include "Engine__Weapon.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeployableController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployableController : public AIController
	{
	public:
		ADD_OBJECT(TrPlayerController, m_SpawnedFromController)
		bool CanFireWeapon(class Weapon* Wpn, byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployableController.CanFireWeapon");
			byte* params = (byte*)malloc(9);
			*(class Weapon**)params = Wpn;
			*(params + 4) = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		byte ScriptGetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployableController.ScriptGetTeamNum");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
