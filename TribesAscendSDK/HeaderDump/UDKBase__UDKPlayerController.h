#pragma once
#include "GameFramework__GamePlayerController.h"
#include "UDKBase__UDKEmitCameraEffect.h"
#include "Engine__CameraAnimInst.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKPlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKPlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKPlayerController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKPlayerController : public GamePlayerController
	{
	public:
		ADD_VAR(::FloatProperty, PulseTimer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VehicleCheckRadiusScaling, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.PostProcessVolume.PostProcessSettings' for the property named 'PostProcessModifier'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.PostProcessVolume.PostProcessSettings' for the property named 'CamOverridePostProcess'!
		ADD_STRUCT(::RotatorProperty, ShakeRot, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ShakeOffset, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUsePhysicsRotation, 0x10)
		ADD_VAR(::BoolProperty, bPulseTeamColor, 0x8)
		ADD_VAR(::BoolProperty, bConsolePlayer, 0x4)
		ADD_VAR(::BoolProperty, bAcuteHearing, 0x2)
		ADD_VAR(::BoolProperty, bDedicatedServerSpectator, 0x1)
		ADD_OBJECT(UDKEmitCameraEffect, CameraEffect)
		ADD_OBJECT(CameraAnimInst, CameraAnimPlayer)
		void SetGamma(float GammaValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.SetGamma");
			byte* params = (byte*)malloc(4);
			*(float*)params = GammaValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetHardwarePhysicsEnabled(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.SetHardwarePhysicsEnabled");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsKeyboardAvailable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.IsKeyboardAvailable");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsMouseAvailable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.IsMouseAvailable");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void RemoveCameraEffect(class UDKEmitCameraEffect* CamEmitter)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.RemoveCameraEffect");
			byte* params = (byte*)malloc(4);
			*(class UDKEmitCameraEffect**)params = CamEmitter;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSpawnCameraEffect(ScriptClass* CameraEffectClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.ClientSpawnCameraEffect");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = CameraEffectClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearCameraEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.ClearCameraEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Pawn* GetTargetAdhesionFrictionTarget(float MaxDistance, Vector& CamLoc, Rotator& CamRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.GetTargetAdhesionFrictionTarget");
			byte* params = (byte*)malloc(32);
			*(float*)params = MaxDistance;
			*(Vector*)(params + 4) = CamLoc;
			*(Rotator*)(params + 16) = CamRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CamLoc = *(Vector*)(params + 4);
			CamRot = *(Rotator*)(params + 16);
			auto returnVal = *(class Pawn**)(params + 28);
			free(params);
			return returnVal;
		}
		bool IsControllerTiltActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.IsControllerTiltActive");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetControllerTiltDesiredIfAvailable(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.SetControllerTiltDesiredIfAvailable");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetControllerTiltActive(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.SetControllerTiltActive");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetOnlyUseControllerTiltInput(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.SetOnlyUseControllerTiltInput");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetUseTiltForwardAndBack(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerController.SetUseTiltForwardAndBack");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
