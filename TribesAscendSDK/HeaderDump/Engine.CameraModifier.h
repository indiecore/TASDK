#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
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
	class CameraModifier : public Object
	{
	public:
		ADD_STRUCT(float, TargetAlpha, 84)
		ADD_STRUCT(float, Alpha, 80)
		ADD_STRUCT(float, AlphaOutTime, 76)
		ADD_STRUCT(float, AlphaInTime, 72)
		ADD_STRUCT(byte, Priority, 68)
		ADD_OBJECT(Camera, CameraOwner, 64)
		ADD_BOOL(bDebug, 60, 0x8)
		ADD_BOOL(bExclusive, 60, 0x4)
		ADD_BOOL(bPendingDisable, 60, 0x2)
		ADD_BOOL(bDisabled, 60, 0x1)
		bool AddCameraModifier(class Camera* Camera)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6408);
			byte params[8] = { NULL };
			*(class Camera**)params = Camera;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ProcessViewRotation(class Actor* ViewTarget, float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6618);
			byte params[36] = { NULL };
			*(class Actor**)params = ViewTarget;
			*(float*)&params[4] = DeltaTime;
			*(Rotator*)&params[8] = out_ViewRotation;
			*(Rotator*)&params[20] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Rotator*)&params[8];
			out_DeltaRot = *(Rotator*)&params[20];
			return *(bool*)&params[32];
		}
		void Init()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12200);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ModifyCamera(class Camera* Camera, float DeltaTime, Object::TPOV& OutPOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12201);
			byte params[40] = { NULL };
			*(class Camera**)params = Camera;
			*(float*)&params[4] = DeltaTime;
			*(Object::TPOV*)&params[8] = OutPOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutPOV = *(Object::TPOV*)&params[8];
			return *(bool*)&params[36];
		}
		bool IsDisabled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12206);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool RemoveCameraModifier(class Camera* Camera)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12212);
			byte params[8] = { NULL };
			*(class Camera**)params = Camera;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DisableModifier(bool bImmediate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12216);
			byte params[4] = { NULL };
			*(bool*)params = bImmediate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableModifier()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12218);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleModifier()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12219);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateAlpha(class Camera* Camera, float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12224);
			byte params[8] = { NULL };
			*(class Camera**)params = Camera;
			*(float*)&params[4] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
