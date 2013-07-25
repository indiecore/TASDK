#pragma once
#include "UTGame.UTMutator.h"
#include "Engine.Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTMutator_SlowTimeKills." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTMutator_SlowTimeKills : public UTMutator
	{
	public:
		ADD_VAR(::FloatProperty, SlowSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RampUpTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SlowTime, 0xFFFFFFFF)
		bool MutatorIsAllowed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator_SlowTimeKills.MutatorIsAllowed");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ScoreKill(class Controller* Killer, class Controller* Killed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator_SlowTimeKills.ScoreKill");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Killed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Timer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator_SlowTimeKills.Timer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
