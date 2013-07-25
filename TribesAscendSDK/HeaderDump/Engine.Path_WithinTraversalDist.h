#pragma once
#include "Engine.PathConstraint.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Path_WithinTraversalDist." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Path_WithinTraversalDist : public PathConstraint
	{
	public:
		ADD_VAR(::FloatProperty, SoftStartPenalty, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSoft, 0x1)
		ADD_VAR(::FloatProperty, MaxTraversalDist, 0xFFFFFFFF)
		bool DontExceedMaxDist(class Pawn* P, float InMaxTraversalDist, bool bInSoft)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_WithinTraversalDist.DontExceedMaxDist");
			byte* params = (byte*)malloc(16);
			*(class Pawn**)params = P;
			*(float*)(params + 4) = InMaxTraversalDist;
			*(bool*)(params + 8) = bInSoft;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_WithinTraversalDist.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
