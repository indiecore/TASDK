#pragma once
#include "Engine.PathConstraint.h"
#include "Core.Object.h"
#include "Engine.Pawn.h"
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
	class Path_WithinDistanceEnvelope : public PathConstraint
	{
	public:
		ADD_STRUCT(Vector, EnvelopeTestPoint, 84)
		ADD_STRUCT(float, SoftStartPenalty, 80)
		ADD_BOOL(bOnlyThrowOutNodesThatLeaveEnvelope, 76, 0x2)
		ADD_BOOL(bSoft, 76, 0x1)
		ADD_STRUCT(float, MinDistance, 72)
		ADD_STRUCT(float, MaxDistance, 68)
		bool StayWithinEnvelopeToLoc(class Pawn* P, Vector InEnvelopeTestPoint, float InMaxDistance, float InMinDistance, bool bInSoft, float InSoftStartPenalty, bool bOnlyTossOutSpecsThatLeave)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24004);
			byte params[40] = { NULL };
			*(class Pawn**)params = P;
			*(Vector*)&params[4] = InEnvelopeTestPoint;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24014);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
