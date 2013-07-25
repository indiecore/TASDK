#pragma once
#include "UTGame__UTMutator.h"
#include "Engine__Controller.h"
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
		// Here lies the not-yet-implemented method 'MutatorIsAllowed'
		// Here lies the not-yet-implemented method 'ScoreKill'
		// Here lies the not-yet-implemented method 'Timer'
	};
}
#undef ADD_VAR
