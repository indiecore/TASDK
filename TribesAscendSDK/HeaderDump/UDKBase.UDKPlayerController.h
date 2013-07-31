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
		struct ObjectiveAnnouncementInfo
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
		ADD_STRUCT(Rotator, ShakeRot, 1488)
		ADD_STRUCT(Vector, ShakeOffset, 1476)
		ADD_BOOL(bUsePhysicsRotation, 1472, 0x10)
		ADD_BOOL(bPulseTeamColor, 1472, 0x8)
		ADD_BOOL(bConsolePlayer, 1472, 0x4)
		ADD_BOOL(bAcuteHearing, 1472, 0x2)
		ADD_BOOL(bDedicatedServerSpectator, 1472, 0x1)
		ADD_OBJECT(UDKEmitCameraEffect, CameraEffect, 1468)
		ADD_OBJECT(CameraAnimInst, CameraAnimPlayer, 1464)
		void SetGamma(float GammaValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35252);
			byte params[4] = { NULL };
			*(float*)params = GammaValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHardwarePhysicsEnabled(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35254);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsKeyboardAvailable()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35256);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsMouseAvailable()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35258);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void RemoveCameraEffect(class UDKEmitCameraEffect* CamEmitter)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35260);
			byte params[4] = { NULL };
			*(class UDKEmitCameraEffect**)params = CamEmitter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSpawnCameraEffect(ScriptClass* CameraEffectClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35262);
			byte params[4] = { NULL };
			*(ScriptClass**)params = CameraEffectClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearCameraEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35266);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Pawn* GetTargetAdhesionFrictionTarget(float MaxDistance, Vector& CamLoc, Rotator& CamRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35267);
			byte params[32] = { NULL };
			*(float*)params = MaxDistance;
			*(Vector*)&params[4] = CamLoc;
			*(Rotator*)&params[16] = CamRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CamLoc = *(Vector*)&params[4];
			CamRot = *(Rotator*)&params[16];
			return *(class Pawn**)&params[28];
		}
		bool IsControllerTiltActive()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35272);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetControllerTiltDesiredIfAvailable(bool bActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35274);
			byte params[4] = { NULL };
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetControllerTiltActive(bool bActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35276);
			byte params[4] = { NULL };
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOnlyUseControllerTiltInput(bool bActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35278);
			byte params[4] = { NULL };
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetUseTiltForwardAndBack(bool bActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35280);
			byte params[4] = { NULL };
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
