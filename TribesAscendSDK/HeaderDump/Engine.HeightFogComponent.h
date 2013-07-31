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
	class HeightFogComponent : public ActorComponent
	{
	public:
		ADD_STRUCT(float, StartDistance, 112)
		ADD_STRUCT(float, ExtinctionDistance, 108)
		ADD_STRUCT(Object::Color, LightColor, 104)
		ADD_STRUCT(float, LightBrightness, 100)
		ADD_STRUCT(float, Density, 96)
		ADD_STRUCT(float, Height, 92)
		ADD_BOOL(bEnabled, 88, 0x1)
		void SetEnabled(bool bSetEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18202);
			byte params[4] = { NULL };
			*(bool*)params = bSetEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
