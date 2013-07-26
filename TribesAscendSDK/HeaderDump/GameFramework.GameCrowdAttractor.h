#pragma once
#include "GameFramework.GameCrowdAgent.h"
#include "GameFramework.GameCrowdForcePoint.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdAttractor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameCrowdAttractor : public GameCrowdForcePoint
	{
	public:
		ADD_VAR(::BoolProperty, bAttractionFalloff, 0x1)
		ADD_VAR(::FloatProperty, Attraction, 0xFFFFFFFF)
		Vector AppliedForce(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAttractor.AppliedForce");
			byte* params = (byte*)malloc(16);
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
