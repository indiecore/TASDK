#pragma once
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
	class NavMeshPath_WithinTraversalDist : public NavMeshPathConstraint
	{
	public:
		ADD_STRUCT(float, SoftStartPenalty, 88)
		ADD_BOOL(bSoft, 84, 0x1)
		ADD_STRUCT(float, MaxTraversalDist, 80)
		bool DontExceedMaxDist(class NavigationHandle* NavHandle, float InMaxTraversalDist, bool bInSoft)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_WithinTraversalDist.DontExceedMaxDist");
			byte params[16] = { NULL };
			*(class NavigationHandle**)&params[0] = NavHandle;
			*(float*)&params[4] = InMaxTraversalDist;
			*(bool*)&params[8] = bInSoft;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_WithinTraversalDist.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
