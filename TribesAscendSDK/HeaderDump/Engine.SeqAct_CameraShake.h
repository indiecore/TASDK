#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.Actor.h"
#include "Engine.CameraShake.h"
#include "Engine.Camera.h"
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
	class SeqAct_CameraShake : public SequenceAction
	{
	public:
		ADD_BOOL(bRadialShake, 240, 0x2)
		ADD_OBJECT(Actor, LocationActor, 260)
		ADD_OBJECT(CameraShake, Shake, 232)
		ADD_STRUCT(float, RadialShake_InnerRadius, 244)
		ADD_STRUCT(float, RadialShake_OuterRadius, 248)
		ADD_STRUCT(float, RadialShake_Falloff, 252)
		ADD_BOOL(bDoControllerVibration, 240, 0x1)
		ADD_BOOL(bOrientTowardRadialEpicenter, 240, 0x4)
		ADD_STRUCT(float, ShakeScale, 236)
		ADD_STRUCT(Camera::ECameraAnimPlaySpace, PlaySpace, 256)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_CameraShake.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
