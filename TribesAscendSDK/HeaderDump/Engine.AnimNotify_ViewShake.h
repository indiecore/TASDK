#pragma once
#include "Engine.AnimNotify_Scripted.h"
#include "Engine.CameraShake.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.AnimNodeSequence.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class AnimNotify_ViewShake : public AnimNotify_Scripted
	{
	public:
		ADD_OBJECT(CameraShake, ShakeParams, 140)
		ADD_STRUCT(ScriptName, BoneName, 132)
		ADD_STRUCT(float, ShakeRadius, 128)
		ADD_BOOL(bUseBoneLocation, 124, 0x2)
		ADD_BOOL(bDoControllerVibration, 124, 0x1)
		ADD_STRUCT(float, FOVFrequency, 120)
		ADD_STRUCT(float, FOVAmplitude, 116)
		ADD_STRUCT(Object::Vector, LocFrequency, 104)
		ADD_STRUCT(Object::Vector, LocAmplitude, 92)
		ADD_STRUCT(Object::Vector, RotFrequency, 80)
		ADD_STRUCT(Object::Vector, RotAmplitude, 68)
		ADD_STRUCT(float, Duration, 64)
		void Notify(class Actor* Owner, class AnimNodeSequence* AnimSeqInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNotify_ViewShake.Notify");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Owner;
			*(class AnimNodeSequence**)&params[4] = AnimSeqInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
