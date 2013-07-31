#pragma once
#include "Engine.ParticleSystemComponent.h"
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
	class UDKParticleSystemComponent : public ParticleSystemComponent
	{
	public:
		ADD_STRUCT(Vector, SavedScale3D, 744)
		ADD_BOOL(bHasSavedScale3D, 740, 0x1)
		ADD_STRUCT(float, FOV, 736)
		void SetFOV(float NewFOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35020);
			byte params[4] = { NULL };
			*(float*)params = NewFOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
