#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "GameFramework.GameThirdPersonCamera.h"
#include "Engine.PostProcessVolume.h"
#include "Engine.Camera.h"
#include "Engine.Pawn.h"
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
	class GameThirdPersonCameraMode : public Object
	{
	public:
		enum ECameraViewportTypes : byte
		{
			CVT_16to9_Full = 0,
			CVT_16to9_VertSplit = 1,
			CVT_16to9_HorizSplit = 2,
			CVT_4to3_Full = 3,
			CVT_4to3_HorizSplit = 4,
			CVT_4to3_VertSplit = 5,
			CVT_MAX = 6,
		};
		struct ViewOffsetData
		{
		public:
			ADD_STRUCT(Vector, OffsetLow, 24)
			ADD_STRUCT(Vector, OffsetMid, 12)
			ADD_STRUCT(Vector, OffsetHigh, 0)
		};
		ADD_OBJECT(GameThirdPersonCamera, ThirdPersonCam, 60)
		ADD_STRUCT(GameThirdPersonCameraMode::ECameraViewportTypes, CurrentViewportType, 556)
		ADD_STRUCT(float, OffsetAdjustmentInterpSpeed, 552)
		ADD_STRUCT(float, ViewOffsetInterp, 548)
		ADD_STRUCT(Object::Vector2D, DOF_RadiusDistRange, 540)
		ADD_STRUCT(Object::Vector2D, DOF_RadiusRange, 532)
		ADD_STRUCT(float, DOF_RadiusFalloff, 528)
		ADD_STRUCT(Vector, DOFTraceExtent, 516)
		ADD_STRUCT(float, DOFDistanceInterpSpeed, 512)
		ADD_STRUCT(float, LastDOFDistance, 508)
		ADD_STRUCT(float, LastDOFRadius, 504)
		ADD_STRUCT(float, DOF_MaxFarBlurAmount, 500)
		ADD_STRUCT(float, DOF_MaxNearBlurAmount, 496)
		ADD_STRUCT(float, DOF_FocusInnerRadius, 492)
		ADD_STRUCT(float, DOF_BlurKernelSize, 488)
		ADD_STRUCT(float, DOF_FalloffExponent, 484)
		ADD_STRUCT(GameThirdPersonCameraMode::ViewOffsetData, ViewOffset_ViewportAdjustments, 268)
		ADD_STRUCT(GameThirdPersonCameraMode::ViewOffsetData, ViewOffset, 232)
		ADD_STRUCT(Vector, TargetRelativeCameraOriginOffset, 220)
		ADD_STRUCT(Vector, WorstLocOffset, 208)
		ADD_STRUCT(Vector, LastRunOffset, 196)
		ADD_STRUCT(float, RunOffsetInterpSpeedOut, 192)
		ADD_STRUCT(float, RunOffsetInterpSpeedIn, 188)
		ADD_STRUCT(float, RunOffsetScalingThreshold, 184)
		ADD_STRUCT(Vector, RunBackAdjustment, 172)
		ADD_STRUCT(Vector, RunFwdAdjustment, 160)
		ADD_STRUCT(Vector, LastStrafeOffset, 148)
		ADD_STRUCT(float, StrafeOffsetInterpSpeedOut, 144)
		ADD_STRUCT(float, StrafeOffsetInterpSpeedIn, 140)
		ADD_STRUCT(float, StrafeOffsetScalingThreshold, 136)
		ADD_STRUCT(Vector, StrafeRightAdjustment, 124)
		ADD_STRUCT(Vector, StrafeLeftAdjustment, 112)
		ADD_STRUCT(float, OriginRotInterpSpeed, 108)
		ADD_STRUCT(Vector, PerAxisOriginLocInterpSpeed, 96)
		ADD_STRUCT(float, OriginLocInterpSpeed, 92)
		ADD_STRUCT(float, FollowingCameraVelThreshold, 88)
		ADD_STRUCT(float, FollowingInterpSpeed_Roll, 84)
		ADD_STRUCT(float, FollowingInterpSpeed_Yaw, 80)
		ADD_STRUCT(float, FollowingInterpSpeed_Pitch, 76)
		ADD_BOOL(bInterpViewOffsetOnlyForCamTransition, 72, 0x8000)
		ADD_BOOL(bNoFOVPostProcess, 72, 0x4000)
		ADD_BOOL(bDOFUpdated, 72, 0x2000)
		ADD_BOOL(bAdjustDOF, 72, 0x1000)
		ADD_BOOL(bApplyDeltaViewOffset, 72, 0x800)
		ADD_BOOL(bSmoothViewOffsetPitchChanges, 72, 0x400)
		ADD_BOOL(bSkipCameraCollision, 72, 0x200)
		ADD_BOOL(bValidateWorstLoc, 72, 0x100)
		ADD_BOOL(bDoPredictiveAvoidance, 72, 0x80)
		ADD_BOOL(bRotInterpSpeedConstant, 72, 0x40)
		ADD_BOOL(bInterpRotation, 72, 0x20)
		ADD_BOOL(bUsePerAxisOriginLocInterp, 72, 0x10)
		ADD_BOOL(bInterpLocation, 72, 0x8)
		ADD_BOOL(bFollowTarget, 72, 0x4)
		ADD_BOOL(bDirectLook, 72, 0x2)
		ADD_BOOL(bLockedToViewTarget, 72, 0x1)
		ADD_STRUCT(float, BlendTime, 68)
		ADD_STRUCT(float, FOVAngle, 64)
		float GetDesiredFOV(class Pawn* ViewedPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32117);
			byte params[8] = { NULL };
			*(class Pawn**)params = ViewedPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool SetFocusPoint(class Pawn* ViewedPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32164);
			byte params[8] = { NULL };
			*(class Pawn**)params = ViewedPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void Init()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32248);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnBecomeActive(class Pawn* TargetPawn, class GameThirdPersonCameraMode* PrevMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32249);
			byte params[8] = { NULL };
			*(class Pawn**)params = TargetPawn;
			*(class GameThirdPersonCameraMode**)&params[4] = PrevMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnBecomeInActive(class Pawn* TargetPawn, class GameThirdPersonCameraMode* NewMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32252);
			byte params[8] = { NULL };
			*(class Pawn**)params = TargetPawn;
			*(class GameThirdPersonCameraMode**)&params[4] = NewMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector AdjustViewOffset(class Pawn* P, Vector Offset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32255);
			byte params[28] = { NULL };
			*(class Pawn**)params = P;
			*(Vector*)&params[4] = Offset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[16];
		}
		Vector GetCameraWorstCaseLoc(class Pawn* TargetPawn, Camera::TViewTarget CurrentViewTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32260);
			byte params[60] = { NULL };
			*(class Pawn**)params = TargetPawn;
			*(Camera::TViewTarget*)&params[4] = CurrentViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[48];
		}
		void ProcessViewRotation(float DeltaTime, class Actor* ViewTarget, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32265);
			byte params[32] = { NULL };
			*(float*)params = DeltaTime;
			*(class Actor**)&params[4] = ViewTarget;
			*(Rotator*)&params[8] = out_ViewRotation;
			*(Rotator*)&params[20] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Rotator*)&params[8];
			out_DeltaRot = *(Rotator*)&params[20];
		}
		Vector GetDOFFocusLoc(class Actor* TraceOwner, Vector StartTrace, Vector EndTrace)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32270);
			byte params[40] = { NULL };
			*(class Actor**)params = TraceOwner;
			*(Vector*)&params[4] = StartTrace;
			*(Vector*)&params[16] = EndTrace;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[28];
		}
		Vector DOFTrace(class Actor* TraceOwner, Vector StartTrace, Vector EndTrace)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32275);
			byte params[40] = { NULL };
			*(class Actor**)params = TraceOwner;
			*(Vector*)&params[4] = StartTrace;
			*(Vector*)&params[16] = EndTrace;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[28];
		}
		void UpdatePostProcess(Camera::TViewTarget& VT, float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32283);
			byte params[48] = { NULL };
			*(Camera::TViewTarget*)params = VT;
			*(float*)&params[44] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			VT = *(Camera::TViewTarget*)params;
		}
		void ModifyPostProcessSettings(PostProcessVolume::PostProcessSettings& PP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32293);
			byte params[220] = { NULL };
			*(PostProcessVolume::PostProcessSettings*)params = PP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PP = *(PostProcessVolume::PostProcessSettings*)params;
		}
		void SetViewOffset(GameThirdPersonCameraMode::ViewOffsetData& NewViewOffset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32295);
			byte params[36] = { NULL };
			*(GameThirdPersonCameraMode::ViewOffsetData*)params = NewViewOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewViewOffset = *(GameThirdPersonCameraMode::ViewOffsetData*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
