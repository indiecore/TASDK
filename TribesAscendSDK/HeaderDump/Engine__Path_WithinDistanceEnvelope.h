#pragma once
#include "Engine__PathConstraint.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Path_WithinDistanceEnvelope." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Path_WithinDistanceEnvelope." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Path_WithinDistanceEnvelope : public PathConstraint
	{
	public:
		ADD_STRUCT(::VectorProperty, EnvelopeTestPoint, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, SoftStartPenalty, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOnlyThrowOutNodesThatLeaveEnvelope, 0x2)
		ADD_VAR(::BoolProperty, bSoft, 0x1)
		ADD_VAR(::FloatProperty, MinDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDistance, 0xFFFFFFFF)
		bool StayWithinEnvelopeToLoc(class Pawn* P, Vector InEnvelopeTestPoint, float InMaxDistance, float InMinDistance, bool bInSoft, float InSoftStartPenalty, bool bOnlyTossOutSpecsThatLeave)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_WithinDistanceEnvelope.StayWithinEnvelopeToLoc");
			byte* params = (byte*)malloc(40);
			*(class Pawn**)params = P;
			*(Vector*)(params + 4) = InEnvelopeTestPoint;
			*(float*)(params + 16) = InMaxDistance;
			*(float*)(params + 20) = InMinDistance;
			*(bool*)(params + 24) = bInSoft;
			*(float*)(params + 28) = InSoftStartPenalty;
			*(bool*)(params + 32) = bOnlyTossOutSpecsThatLeave;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 36);
			free(params);
			return returnVal;
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_WithinDistanceEnvelope.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
