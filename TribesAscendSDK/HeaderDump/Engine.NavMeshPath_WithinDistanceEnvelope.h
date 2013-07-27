#pragma once
#include "Core.Object.h"
#include "Engine.NavMeshPathConstraint.h"
#include "Engine.NavigationHandle.h"
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
	class NavMeshPath_WithinDistanceEnvelope : public NavMeshPathConstraint
	{
	public:
		ADD_STRUCT(Object::Vector, EnvelopeTestPoint, 96)
		ADD_STRUCT(float, SoftStartPenalty, 92)
		ADD_BOOL(bOnlyThrowOutNodesThatLeaveEnvelope, 88, 0x2)
		ADD_BOOL(bSoft, 88, 0x1)
		ADD_STRUCT(float, MinDistance, 84)
		ADD_STRUCT(float, MaxDistance, 80)
		bool StayWithinEnvelopeToLoc(class NavigationHandle* NavHandle, Object::Vector InEnvelopeTestPoint, float InMaxDistance, float InMinDistance, bool bInSoft, float InSoftStartPenalty, bool bOnlyTossOutSpecsThatLeave)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_WithinDistanceEnvelope.StayWithinEnvelopeToLoc");
			byte params[40] = { NULL };
			*(class NavigationHandle**)&params[0] = NavHandle;
			*(Object::Vector*)&params[4] = InEnvelopeTestPoint;
			*(float*)&params[16] = InMaxDistance;
			*(float*)&params[20] = InMinDistance;
			*(bool*)&params[24] = bInSoft;
			*(float*)&params[28] = InSoftStartPenalty;
			*(bool*)&params[32] = bOnlyTossOutSpecsThatLeave;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[36];
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_WithinDistanceEnvelope.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
