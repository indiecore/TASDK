#pragma once
#include "Engine.AIController.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.Weapon.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployableController : public AIController
	{
	public:
		ADD_OBJECT(TrPlayerController, m_SpawnedFromController, 924)
		bool CanFireWeapon(class Weapon* Wpn, byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployableController.CanFireWeapon");
			byte params[9] = { NULL };
			*(class Weapon**)&params[0] = Wpn;
			params[4] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		byte ScriptGetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployableController.ScriptGetTeamNum");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[0];
		}
	};
}
#undef ADD_OBJECT
