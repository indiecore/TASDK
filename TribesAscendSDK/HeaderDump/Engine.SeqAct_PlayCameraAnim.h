#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.Actor.h"
#include "Engine.Camera.h"
#include "Engine.CameraAnim.h"
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
	class SeqAct_PlayCameraAnim : public SequenceAction
	{
	public:
		ADD_OBJECT(Actor, UserDefinedSpaceActor, 260)
		ADD_STRUCT(Camera::ECameraAnimPlaySpace, PlaySpace, 256)
		ADD_STRUCT(float, IntensityScale, 252)
		ADD_STRUCT(float, Rate, 248)
		ADD_STRUCT(float, BlendOutTime, 244)
		ADD_STRUCT(float, BlendInTime, 240)
		ADD_BOOL(bRandomStartTime, 236, 0x2)
		ADD_BOOL(bLoop, 236, 0x1)
		ADD_OBJECT(CameraAnim, CameraAnim, 232)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_PlayCameraAnim.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
