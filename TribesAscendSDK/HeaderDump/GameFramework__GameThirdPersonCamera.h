#pragma once
#include "GameFramework__GamePlayerCamera.h"
#include "GameFramework__GameCameraBase.h"
#include "Engine__Actor.h"
#include "GameFramework__GameThirdPersonCameraMode.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameThirdPersonCamera." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameThirdPersonCamera." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameThirdPersonCamera." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameThirdPersonCamera : public GameCameraBase
	{
	public:
		ADD_STRUCT(::VectorProperty, LastOffsetAdjustment, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, LastPreModifierCameraRot, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LastPreModifierCameraLoc, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LastWorstLocationLocal, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, WorstLocInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DirectLookInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DirectLookYaw, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastPostCamTurnYaw, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TurnDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TurnTotalTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TurnEndAngle, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TurnStartAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TurnCurTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDebugChangedCameraMode, 0x40)
		ADD_VAR(::BoolProperty, bDoingDirectLook, 0x20)
		ADD_VAR(::BoolProperty, bDrawDebug, 0x10)
		ADD_VAR(::BoolProperty, bTurnAlignTargetWhenFinished, 0x8)
		ADD_VAR(::BoolProperty, bDoingACameraTurn, 0x4)
		ADD_VAR(::BoolProperty, bFocusPointSuccessful, 0x2)
		ADD_VAR(::BoolProperty, bFocusPointSet, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.GameThirdPersonCamera.CamFocusPointParams' for the property named 'FocusPoint'!
		ADD_STRUCT(::VectorProperty, LastFocusPointLoc, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, ActualFocusPointWorldLoc, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, LastFocusChangeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Focus_FastAdjustKickInTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Focus_MaxTries, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Focus_StepHeightAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Focus_BackOffStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LeftoverPitchAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastYawAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPitchAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHeightAdjustment, 0xFFFFFFFF)
		ADD_OBJECT(GameThirdPersonCameraMode, CurrentCamMode)
		ADD_OBJECT(ScriptClass, ThirdPersonCamDefaultClass)
		ADD_OBJECT(GameThirdPersonCameraMode, ThirdPersonCamDefault)
		ADD_VAR(::FloatProperty, LastCamFOV, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastViewOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, OriginOffsetInterpSpeed, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, LastActualCameraOriginRot, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LastActualOriginOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, PenetrationExtentScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PenetrationBlockedPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PenetrationBlendInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PenetrationBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WorstLocPenetrationExtentScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WorstLocBlockedPct, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastActualCameraOrigin, 0xFFFFFFFF
		class GameThirdPersonCameraMode* CreateCameraMode(ScriptClass* ModeClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.CreateCameraMode");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = ModeClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GameThirdPersonCameraMode**)(params + 4);
			free(params);
			return returnVal;
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetDesiredFOV(class Pawn* ViewedPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.GetDesiredFOV");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = ViewedPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void UpdateCamera(class Pawn* P, class GamePlayerCamera* CameraActor, float DeltaTime, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void*& OutVT)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.UpdateCamera");
			byte* params = (byte*)malloc(56);
			*(class Pawn**)params = P;
			*(class GamePlayerCamera**)(params + 4) = CameraActor;
			*(float*)(params + 8) = DeltaTime;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)(params + 12) = OutVT;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutVT = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)(params + 12);
			free(params);
		}
		void UpdateCameraMode(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.UpdateCameraMode");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayerUpdateCamera(class Pawn* P, class GamePlayerCamera* CameraActor, float DeltaTime, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void*& OutVT)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.PlayerUpdateCamera");
			byte* params = (byte*)malloc(56);
			*(class Pawn**)params = P;
			*(class GamePlayerCamera**)(params + 4) = CameraActor;
			*(float*)(params + 8) = DeltaTime;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)(params + 12) = OutVT;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutVT = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)(params + 12);
			free(params);
		}
		void BeginTurn(int StartAngle, int EndAngle, float TimeSec, float DelaySec, bool bAlignTargetWhenFinished)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.BeginTurn");
			byte* params = (byte*)malloc(20);
			*(int*)params = StartAngle;
			*(int*)(params + 4) = EndAngle;
			*(float*)(params + 8) = TimeSec;
			*(float*)(params + 12) = DelaySec;
			*(bool*)(params + 16) = bAlignTargetWhenFinished;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndTurn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.EndTurn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdjustTurn(int AngleOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.AdjustTurn");
			byte* params = (byte*)malloc(4);
			*(int*)params = AngleOffset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFocusOnLoc(Vector FocusWorldLoc, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* InterpSpeedRange, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* InFocusFOV, float CameraFOV, bool bAlwaysFocus, bool bAdjustCamera, bool bIgnoreTrace, float FocusPitchOffsetDeg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.SetFocusOnLoc");
			byte* params = (byte*)malloc(48);
			*(Vector*)params = FocusWorldLoc;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 12) = InterpSpeedRange;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 20) = InFocusFOV;
			*(float*)(params + 28) = CameraFOV;
			*(bool*)(params + 32) = bAlwaysFocus;
			*(bool*)(params + 36) = bAdjustCamera;
			*(bool*)(params + 40) = bIgnoreTrace;
			*(float*)(params + 44) = FocusPitchOffsetDeg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFocusOnActor(class Actor* FocusActor, ScriptName FocusBoneName, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* InterpSpeedRange, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* InFocusFOV, float CameraFOV, bool bAlwaysFocus, bool bAdjustCamera, bool bIgnoreTrace, float FocusPitchOffsetDeg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.SetFocusOnActor");
			byte* params = (byte*)malloc(48);
			*(class Actor**)params = FocusActor;
			*(ScriptName*)(params + 4) = FocusBoneName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 12) = InterpSpeedRange;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 20) = InFocusFOV;
			*(float*)(params + 28) = CameraFOV;
			*(bool*)(params + 32) = bAlwaysFocus;
			*(bool*)(params + 36) = bAdjustCamera;
			*(bool*)(params + 40) = bIgnoreTrace;
			*(float*)(params + 44) = FocusPitchOffsetDeg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Actor* GetFocusActor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.GetFocusActor");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)params;
			free(params);
			return returnVal;
		}
		void ClearFocusPoint(bool bLeaveCameraRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.ClearFocusPoint");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bLeaveCameraRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateFocusPoint(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.UpdateFocusPoint");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector GetActualFocusLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.GetActualFocusLocation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void AdjustFocusPointInterpolation(Rotator Delta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.AdjustFocusPointInterpolation");
			byte* params = (byte*)malloc(12);
			*(Rotator*)params = Delta;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GameThirdPersonCameraMode* FindBestCameraMode(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.FindBestCameraMode");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GameThirdPersonCameraMode**)(params + 4);
			free(params);
			return returnVal;
		}
		void ProcessViewRotation(float DeltaTime, class Actor* ViewTarget, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.ProcessViewRotation");
			byte* params = (byte*)malloc(32);
			*(float*)params = DeltaTime;
			*(class Actor**)(params + 4) = ViewTarget;
			*(Rotator*)(params + 8) = out_ViewRotation;
			*(Rotator*)(params + 20) = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ViewRotation = *(Rotator*)(params + 8);
			out_DeltaRot = *(Rotator*)(params + 20);
			free(params);
		}
		void OnBecomeActive(class GameCameraBase* OldCamera)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.OnBecomeActive");
			byte* params = (byte*)malloc(4);
			*(class GameCameraBase**)params = OldCamera;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ModifyPostProcessSettings(
// WARNING: Unknown structure type 'ScriptStruct Engine.PostProcessVolume.PostProcessSettings'!
void*& PP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.ModifyPostProcessSettings");
			byte* params = (byte*)malloc(220);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.PostProcessVolume.PostProcessSettings'!
void**)params = PP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PP = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.PostProcessVolume.PostProcessSettings'!
void**)params;
			free(params);
		}
		void ResetInterpolation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.ResetInterpolation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
