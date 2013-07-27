#pragma once
#include "Engine.PointLightComponent.h"
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
	class UDKExplosionLight : public PointLightComponent
	{
	public:
		struct LightValues
		{
		public:
			ADD_STRUCT(Object::Color, LightColor, 12)
			ADD_STRUCT(float, Brightness, 8)
			ADD_STRUCT(float, Radius, 4)
			ADD_STRUCT(float, StartTime, 0)
		};
		ADD_STRUCT(ScriptArray<UDKExplosionLight::LightValues>, TimeShift, 600)
		ADD_STRUCT(int, TimeShiftIndex, 596)
		ADD_STRUCT(float, Lifetime, 592)
		ADD_STRUCT(float, HighDetailFrameTime, 588)
		ADD_BOOL(bInitialized, 584, 0x2)
		ADD_BOOL(bCheckFrameRate, 584, 0x1)
		void OnLightFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Light)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34820);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Light;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetLight()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34830);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
