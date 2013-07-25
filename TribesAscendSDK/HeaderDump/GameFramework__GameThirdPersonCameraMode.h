#pragma once
#include "Core__Object.h"
#include "Engine__Pawn.h"
#include "GameFramework__GameThirdPersonCamera.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameThirdPersonCameraMode." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameThirdPersonCameraMode." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameThirdPersonCameraMode." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameThirdPersonCameraMode : public Object
	{
	public:
		ADD_OBJECT(GameThirdPersonCamera, ThirdPersonCam)
		ADD_VAR(::ByteProperty, CurrentViewportType, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OffsetAdjustmentInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewOffsetInterp, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'DOF_RadiusDistRange'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'DOF_RadiusRange'!
		ADD_VAR(::FloatProperty, DOF_RadiusFalloff, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, DOFTraceExtent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DOFDistanceInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastDOFDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastDOFRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DOF_MaxFarBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DOF_MaxNearBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DOF_FocusInnerRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DOF_BlurKernelSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DOF_FalloffExponent, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.GameThirdPersonCameraMode.ViewOffsetData' for the property named 'ViewOffset_ViewportAdjustments'!
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.GameThirdPersonCameraMode.ViewOffsetData' for the property named 'ViewOffset'!
		ADD_STRUCT(::VectorProperty, TargetRelativeCameraOriginOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, WorstLocOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastRunOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RunOffsetInterpSpeedOut, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RunOffsetInterpSpeedIn, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RunOffsetScalingThreshold, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RunBackAdjustment, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RunFwdAdjustment, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastStrafeOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StrafeOffsetInterpSpeedOut, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StrafeOffsetInterpSpeedIn, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StrafeOffsetScalingThreshold, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StrafeRightAdjustment, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StrafeLeftAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OriginRotInterpSpeed, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PerAxisOriginLocInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OriginLocInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FollowingCameraVelThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FollowingInterpSpeed_Roll, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FollowingInterpSpeed_Yaw, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FollowingInterpSpeed_Pitch, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bInterpViewOffsetOnlyForCamTransition, 0x8000)
		ADD_VAR(::BoolProperty, bNoFOVPostProcess, 0x4000)
		ADD_VAR(::BoolProperty, bDOFUpdated, 0x2000)
		ADD_VAR(::BoolProperty, bAdjustDOF, 0x1000)
		ADD_VAR(::BoolProperty, bApplyDeltaViewOffset, 0x800)
		ADD_VAR(::BoolProperty, bSmoothViewOffsetPitchChanges, 0x400)
		ADD_VAR(::BoolProperty, bSkipCameraCollision, 0x200)
		ADD_VAR(::BoolProperty, bValidateWorstLoc, 0x100)
		ADD_VAR(::BoolProperty, bDoPredictiveAvoidance, 0x80)
		ADD_VAR(::BoolProperty, bRotInterpSpeedConstant, 0x40)
		ADD_VAR(::BoolProperty, bInterpRotation, 0x20)
		ADD_VAR(::BoolProperty, bUsePerAxisOriginLocInterp, 0x10)
		ADD_VAR(::BoolProperty, bInterpLocation, 0x8)
		ADD_VAR(::BoolProperty, bFollowTarget, 0x4)
		ADD_VAR(::BoolProperty, bDirectLook, 0x2)
		ADD_VAR(::BoolProperty, bLockedToViewTarget, 0x1)
		ADD_VAR(::FloatProperty, BlendTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FOVAngle, 0xFFFFFFFF)
		float GetDesiredFOV(class Pawn* ViewedPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCameraMode.GetDesiredFOV");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = ViewedPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetFocusPoint(class Pawn* ViewedPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCameraMode.SetFocusPoint");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = ViewedPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCameraMode.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnBecomeActive(class Pawn* TargetPawn, class GameThirdPersonCameraMode* PrevMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCameraMode.OnBecomeActive");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = TargetPawn;
			*(class GameThirdPersonCameraMode**)(params + 4) = PrevMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnBecomeInActive(class Pawn* TargetPawn, class GameThirdPersonCameraMode* NewMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCameraMode.OnBecomeInActive");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = TargetPawn;
			*(class GameThirdPersonCameraMode**)(params + 4) = NewMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector AdjustViewOffset(class Pawn* P, Vector Offset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCameraMode.AdjustViewOffset");
			byte* params = (byte*)malloc(28);
			*(class Pawn**)params = P;
			*(Vector*)(params + 4) = Offset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 16);
			free(params);
			return returnVal;
		}
		Vector GetCameraWorstCaseLoc(class Pawn* TargetPawn, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void* CurrentViewTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCameraMode.GetCameraWorstCaseLoc");
			byte* params = (byte*)malloc(60);
			*(class Pawn**)params = TargetPawn;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)(params + 4) = CurrentViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 48);
			free(params);
			return returnVal;
		}
		void ProcessViewRotation(float DeltaTime, class Actor* ViewTarget, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCameraMode.ProcessViewRotation");
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
		Vector GetDOFFocusLoc(class Actor* TraceOwner, Vector StartTrace, Vector EndTrace)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCameraMode.GetDOFFocusLoc");
			byte* params = (byte*)malloc(40);
			*(class Actor**)params = TraceOwner;
			*(Vector*)(params + 4) = StartTrace;
			*(Vector*)(params + 16) = EndTrace;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 28);
			free(params);
			return returnVal;
		}
		Vector DOFTrace(class Actor* TraceOwner, Vector StartTrace, Vector EndTrace)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCameraMode.DOFTrace");
			byte* params = (byte*)malloc(40);
			*(class Actor**)params = TraceOwner;
			*(Vector*)(params + 4) = StartTrace;
			*(Vector*)(params + 16) = EndTrace;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 28);
			free(params);
			return returnVal;
		}
		void UpdatePostProcess(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void*& VT, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCameraMode.UpdatePostProcess");
			byte* params = (byte*)malloc(48);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)params = VT;
			*(float*)(params + 44) = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			VT = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)params;
			free(params);
		}
		void ModifyPostProcessSettings(
// WARNING: Unknown structure type 'ScriptStruct Engine.PostProcessVolume.PostProcessSettings'!
void*& PP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCameraMode.ModifyPostProcessSettings");
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
		void SetViewOffset(
// WARNING: Unknown structure type 'ScriptStruct GameFramework.GameThirdPersonCameraMode.ViewOffsetData'!
void*& NewViewOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCameraMode.SetViewOffset");
			byte* params = (byte*)malloc(36);
			*(
// WARNING: Unknown structure type 'ScriptStruct GameFramework.GameThirdPersonCameraMode.ViewOffsetData'!
void**)params = NewViewOffset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			NewViewOffset = *(
// WARNING: Unknown structure type 'ScriptStruct GameFramework.GameThirdPersonCameraMode.ViewOffsetData'!
void**)params;
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
