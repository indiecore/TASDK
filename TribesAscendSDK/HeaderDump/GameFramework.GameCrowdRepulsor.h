#pragma once
#include "GameFramework.GameCrowdAgent.h"
#include "GameFramework.GameCrowdForcePoint.h"
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GameCrowdRepulsor : public GameCrowdForcePoint
	{
	public:
		ADD_BOOL(bAttractionFalloff, 488, 0x1)
		ADD_STRUCT(float, Repulsion, 484)
		Vector AppliedForce(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31507);
			byte params[16] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
