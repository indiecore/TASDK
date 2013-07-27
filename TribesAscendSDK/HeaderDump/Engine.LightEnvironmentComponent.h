#pragma once
#include "Engine.ActorComponent.h"
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
	class LightEnvironmentComponent : public ActorComponent
	{
	public:
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, AffectedComponents, 100)
		ADD_STRUCT(float, DominantShadowFactor, 92)
		ADD_BOOL(bTranslucencyShadowed, 88, 0x10)
		ADD_BOOL(bAllowPreShadow, 88, 0x8)
		ADD_BOOL(bAllowDynamicShadowsOnTranslucency, 88, 0x4)
		ADD_BOOL(bForceNonCompositeDynamicLights, 88, 0x2)
		ADD_BOOL(bEnabled, 88, 0x1)
		void SetEnabled(bool bNewEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightEnvironmentComponent.SetEnabled");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsEnabled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightEnvironmentComponent.IsEnabled");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
