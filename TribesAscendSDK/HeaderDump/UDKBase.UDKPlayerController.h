#pragma once
#include "Engine.Pawn.h"
#include "Engine.PostProcessVolume.h"
#include "GameFramework.GamePlayerController.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "UDKBase.UDKEmitCameraEffect.h"
#include "Engine.CameraAnimInst.h"
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
	class UDKPlayerController : public GamePlayerController
	{
	public:
		class ObjectiveAnnouncementInfo
		{
		public:
			ADD_STRUCT(ScriptString*, AnnouncementText, 4)
			ADD_OBJECT(SoundNodeWave, AnnouncementSound, 0)
		};
		ADD_STRUCT(ScriptArray<class Actor*>, PotentiallyHiddenActors, 1940)
		ADD_STRUCT(float, PulseTimer, 1956)
		ADD_STRUCT(float, VehicleCheckRadiusScaling, 1952)
		ADD_STRUCT(PostProcessVolume::PostProcessSettings, PostProcessModifier, 1720)
		ADD_STRUCT(PostProcessVolume::PostProcessSettings, CamOverridePostProcess, 1500)
		ADD_STRUCT(Object::Rotator, ShakeRot, 1488)
		ADD_STRUCT(Object::Vector, ShakeOffset, 1476)
		ADD_BOOL(bUsePhysicsRotation, 1472, 0x10)
		ADD_BOOL(bPulseTeamColor, 1472, 0x8)
		ADD_BOOL(bConsolePlayer, 1472, 0x4)
		ADD_BOOL(bAcuteHearing, 1472, 0x2)
		ADD_BOOL(bDedicatedServerSpectator, 1472, 0x1)
		ADD_OBJECT(UDKEmitCameraEffect, CameraEffect, 1468)
		ADD_OBJECT(CameraAnimInst, CameraAnimPlayer, 1464)
		void SetGamma(float GammaValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.SetGamma");
			byte params[4] = { NULL };
			*(float*)&params[0] = GammaValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHardwarePhysicsEnabled(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.SetHardwarePhysicsEnabled");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsKeyboardAvailable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.IsKeyboardAvailable");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsMouseAvailable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.IsMouseAvailable");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void RemoveCameraEffect(class UDKEmitCameraEffect* CamEmitter)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.RemoveCameraEffect");
			byte params[4] = { NULL };
			*(class UDKEmitCameraEffect**)&params[0] = CamEmitter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSpawnCameraEffect(ScriptClass* CameraEffectClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.ClientSpawnCameraEffect");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = CameraEffectClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearCameraEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.ClearCameraEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Pawn* GetTargetAdhesionFrictionTarget(float MaxDistance, Object::Vector& CamLoc, Object::Rotator& CamRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.GetTargetAdhesionFrictionTarget");
			byte params[32] = { NULL };
			*(float*)&params[0] = MaxDistance;
			*(Object::Vector*)&params[4] = CamLoc;
			*(Object::Rotator*)&params[16] = CamRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CamLoc = *(Object::Vector*)&params[4];
			CamRot = *(Object::Rotator*)&params[16];
			return *(class Pawn**)&params[28];
		}
		bool IsControllerTiltActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.IsControllerTiltActive");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SetControllerTiltDesiredIfAvailable(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.SetControllerTiltDesiredIfAvailable");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetControllerTiltActive(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.SetControllerTiltActive");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOnlyUseControllerTiltInput(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.SetOnlyUseControllerTiltInput");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetUseTiltForwardAndBack(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.SetUseTiltForwardAndBack");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
