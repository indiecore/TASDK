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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.AddCameraModifier");
			byte params[8] = { NULL };
			*(class Camera**)&params[0] = Camera;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ProcessViewRotation(class Actor* ViewTarget, float DeltaTime, Object::Rotator& out_ViewRotation, Object::Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.ProcessViewRotation");
			byte params[36] = { NULL };
			*(class Actor**)&params[0] = ViewTarget;
			*(float*)&params[4] = DeltaTime;
			*(Object::Rotator*)&params[8] = out_ViewRotation;
			*(Object::Rotator*)&params[20] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Object::Rotator*)&params[8];
			out_DeltaRot = *(Object::Rotator*)&params[20];
			return *(bool*)&params[32];
		}
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ModifyCamera(class Camera* Camera, float DeltaTime, Object::TPOV& OutPOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.ModifyCamera");
			byte params[40] = { NULL };
			*(class Camera**)&params[0] = Camera;
			*(float*)&params[4] = DeltaTime;
			*(Object::TPOV*)&params[8] = OutPOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutPOV = *(Object::TPOV*)&params[8];
			return *(bool*)&params[36];
		}
		bool IsDisabled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.IsDisabled");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool RemoveCameraModifier(class Camera* Camera)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.RemoveCameraModifier");
			byte params[8] = { NULL };
			*(class Camera**)&params[0] = Camera;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DisableModifier(bool bImmediate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.DisableModifier");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bImmediate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableModifier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.EnableModifier");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleModifier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.ToggleModifier");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateAlpha(class Camera* Camera, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.UpdateAlpha");
			byte params[8] = { NULL };
			*(class Camera**)&params[0] = Camera;
			*(float*)&params[4] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
