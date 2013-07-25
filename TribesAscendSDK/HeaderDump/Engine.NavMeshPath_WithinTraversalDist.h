#pragma once
#include "Engine.NavMeshPathConstraint.h"
#include "Engine.NavigationHandle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshPath_WithinTraversalDist." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshPath_WithinTraversalDist : public NavMeshPathConstraint
	{
	public:
		ADD_VAR(::FloatProperty, SoftStartPenalty, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSoft, 0x1)
		ADD_VAR(::FloatProperty, MaxTraversalDist, 0xFFFFFFFF)
		bool DontExceedMaxDist(class NavigationHandle* NavHandle, float InMaxTraversalDist, bool bInSoft)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_WithinTraversalDist.DontExceedMaxDist");
			byte* params = (byte*)malloc(16);
			*(class NavigationHandle**)params = NavHandle;
			*(float*)(params + 4) = InMaxTraversalDist;
			*(bool*)(params + 8) = bInSoft;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_WithinTraversalDist.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
