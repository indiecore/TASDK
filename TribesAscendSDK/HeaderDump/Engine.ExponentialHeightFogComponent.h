#pragma once
#include "Engine.ActorComponent.h"
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
	class ExponentialHeightFogComponent : public ActorComponent
	{
	public:
		ADD_STRUCT(Object::Color, LightInscatteringColor, 128)
		ADD_STRUCT(float, LightInscatteringBrightness, 124)
		ADD_STRUCT(Object::Color, OppositeLightColor, 120)
		ADD_STRUCT(float, OppositeLightBrightness, 116)
		ADD_STRUCT(float, LightTerminatorAngle, 112)
		ADD_STRUCT(float, StartDistance, 108)
		ADD_STRUCT(float, FogMaxOpacity, 104)
		ADD_STRUCT(float, FogHeightFalloff, 100)
		ADD_STRUCT(float, FogDensity, 96)
		ADD_STRUCT(float, FogHeight, 92)
		ADD_BOOL(bEnabled, 88, 0x1)
		void SetEnabled(bool bSetEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ExponentialHeightFogComponent.SetEnabled");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bSetEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
