#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.PostProcessVolume.h"
#include "Engine.HUD.h"
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
	class CameraActor : public Actor
	{
	public:
		ADD_BOOL(bConstrainAspectRatio, 476, 0x1)
		ADD_STRUCT(float, AspectRatio, 480)
		ADD_STRUCT(float, CamOverridePostProcessAlpha, 488)
		ADD_STRUCT(PostProcessVolume::PostProcessSettings, CamOverridePostProcess, 492)
		ADD_STRUCT(float, FOVAngle, 484)
		ADD_BOOL(bCamOverridePostProcess, 476, 0x2)
		void GetCameraView(float DeltaTime, Object::TPOV& OutPOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12119);
			byte params[32] = { NULL };
			*(float*)params = DeltaTime;
			*(Object::TPOV*)&params[4] = OutPOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutPOV = *(Object::TPOV*)&params[4];
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12122);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
