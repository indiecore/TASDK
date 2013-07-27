#pragma once
#include "Engine.PostProcessVolume.h"
#include "Engine.Camera.h"
#include "Engine.Pawn.h"
#include "GameFramework.GameCameraBase.h"
#include "Engine.Actor.h"
#include "GameFramework.GameThirdPersonCameraMode.h"
#include "Core.Object.h"
#include "GameFramework.GamePlayerCamera.h"
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
	class GameThirdPersonCamera : public GameCameraBase
	{
	public:
		class PenetrationAvoidanceFeeler
		{
		public:
			ADD_STRUCT(int, FramesUntilNextTrace, 36)
			ADD_STRUCT(int, TraceInterval, 32)
			ADD_STRUCT(Object::Vector, Extent, 20)
			ADD_STRUCT(float, PawnWeight, 16)
			ADD_STRUCT(float, WorldWeight, 12)
			ADD_STRUCT(Object::Rotator, AdjustmentRot, 0)
		};
		class CamFocusPointParams
		{
		public:
			ADD_STRUCT(float, FocusPitchOffsetDeg, 48)
			ADD_BOOL(bIgnoreTrace, 44, 0x4)
			ADD_BOOL(bAdjustCamera, 44, 0x2)
			ADD_BOOL(bAlwaysFocus, 44, 0x1)
			ADD_STRUCT(Object::Vector2D, InFocusFOV, 36)
			ADD_STRUCT(Object::Vector2D, InterpSpeedRange, 28)
			ADD_STRUCT(float, CameraFOV, 24)
			ADD_STRUCT(Object::Vector, FocusWorldLoc, 12)
			ADD_STRUCT(ScriptName, FocusBoneName, 4)
			ADD_OBJECT(Actor, FocusActor, 0)
		};
		ADD_STRUCT(ScriptArray<GameThirdPersonCamera::PenetrationAvoidanceFeeler>, PenetrationAvoidanceFeelers, 348)
		ADD_STRUCT(Object::Vector, LastOffsetAdjustment, 360)
		ADD_STRUCT(Object::Rotator, LastPreModifierCameraRot, 336)
		ADD_STRUCT(Object::Vector, LastPreModifierCameraLoc, 324)
		ADD_STRUCT(Object::Vector, LastWorstLocationLocal, 312)
		ADD_STRUCT(float, WorstLocInterpSpeed, 308)
		ADD_STRUCT(float, DirectLookInterpSpeed, 304)
		ADD_STRUCT(int, DirectLookYaw, 300)
		ADD_STRUCT(int, LastPostCamTurnYaw, 296)
		ADD_STRUCT(float, TurnDelay, 292)
		ADD_STRUCT(float, TurnTotalTime, 288)
		ADD_STRUCT(int, TurnEndAngle, 284)
		ADD_STRUCT(int, TurnStartAngle, 280)
		ADD_STRUCT(float, TurnCurTime, 276)
		ADD_BOOL(bDebugChangedCameraMode, 272, 0x40)
		ADD_BOOL(bDoingDirectLook, 272, 0x20)
		ADD_BOOL(bDrawDebug, 272, 0x10)
		ADD_BOOL(bTurnAlignTargetWhenFinished, 272, 0x8)
		ADD_BOOL(bDoingACameraTurn, 272, 0x4)
		ADD_BOOL(bFocusPointSuccessful, 272, 0x2)
		ADD_BOOL(bFocusPointSet, 272, 0x1)
		ADD_STRUCT(GameThirdPersonCamera::CamFocusPointParams, FocusPoint, 220)
		ADD_STRUCT(Object::Vector, LastFocusPointLoc, 208)
		ADD_STRUCT(Object::Vector, ActualFocusPointWorldLoc, 196)
		ADD_STRUCT(float, LastFocusChangeTime, 192)
		ADD_STRUCT(float, Focus_FastAdjustKickInTime, 188)
		ADD_STRUCT(int, Focus_MaxTries, 184)
		ADD_STRUCT(float, Focus_StepHeightAdjustment, 180)
		ADD_STRUCT(float, Focus_BackOffStrength, 176)
		ADD_STRUCT(float, LeftoverPitchAdjustment, 172)
		ADD_STRUCT(float, LastYawAdjustment, 168)
		ADD_STRUCT(float, LastPitchAdjustment, 164)
		ADD_STRUCT(float, LastHeightAdjustment, 160)
		ADD_OBJECT(GameThirdPersonCameraMode, CurrentCamMode, 156)
		ADD_OBJECT(ScriptClass, ThirdPersonCamDefaultClass, 152)
		ADD_OBJECT(GameThirdPersonCameraMode, ThirdPersonCamDefault, 148)
		ADD_STRUCT(float, LastCamFOV, 144)
		ADD_STRUCT(Object::Vector, LastViewOffset, 132)
		ADD_STRUCT(float, OriginOffsetInterpSpeed, 128)
		ADD_STRUCT(Object::Rotator, LastActualCameraOriginRot, 116)
		ADD_STRUCT(Object::Vector, LastActualOriginOffset, 104)
		ADD_STRUCT(float, PenetrationExtentScale, 100)
		ADD_STRUCT(float, PenetrationBlockedPct, 96)
		ADD_STRUCT(float, PenetrationBlendInTime, 92)
		ADD_STRUCT(float, PenetrationBlendOutTime, 88)
		ADD_STRUCT(float, WorstLocPenetrationExtentScale, 84)
		ADD_STRUCT(float, WorstLocBlockedPct, 80)
		ADD_STRUCT(Object::Vector, LastActualCameraOrigin, 68)
		class GameThirdPersonCameraMode* CreateCameraMode(ScriptClass* ModeClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.CreateCameraMode");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = ModeClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GameThirdPersonCameraMode**)&params[4];
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
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = ViewedPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void UpdateCamera(class Pawn* P, class GamePlayerCamera* CameraActor, float DeltaTime, Camera::TViewTarget& OutVT)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.UpdateCamera");
			byte params[56] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(class GamePlayerCamera**)&params[4] = CameraActor;
			*(float*)&params[8] = DeltaTime;
			*(Camera::TViewTarget*)&params[12] = OutVT;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutVT = *(Camera::TViewTarget*)&params[12];
		}
		void UpdateCameraMode(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.UpdateCameraMode");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayerUpdateCamera(class Pawn* P, class GamePlayerCamera* CameraActor, float DeltaTime, Camera::TViewTarget& OutVT)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.PlayerUpdateCamera");
			byte params[56] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(class GamePlayerCamera**)&params[4] = CameraActor;
			*(float*)&params[8] = DeltaTime;
			*(Camera::TViewTarget*)&params[12] = OutVT;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutVT = *(Camera::TViewTarget*)&params[12];
		}
		void BeginTurn(int StartAngle, int EndAngle, float TimeSec, float DelaySec, bool bAlignTargetWhenFinished)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.BeginTurn");
			byte params[20] = { NULL };
			*(int*)&params[0] = StartAngle;
			*(int*)&params[4] = EndAngle;
			*(float*)&params[8] = TimeSec;
			*(float*)&params[12] = DelaySec;
			*(bool*)&params[16] = bAlignTargetWhenFinished;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndTurn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.EndTurn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdjustTurn(int AngleOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.AdjustTurn");
			byte params[4] = { NULL };
			*(int*)&params[0] = AngleOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFocusOnLoc(Object::Vector FocusWorldLoc, Object::Vector2D InterpSpeedRange, Object::Vector2D InFocusFOV, float CameraFOV, bool bAlwaysFocus, bool bAdjustCamera, bool bIgnoreTrace, float FocusPitchOffsetDeg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.SetFocusOnLoc");
			byte params[48] = { NULL };
			*(Object::Vector*)&params[0] = FocusWorldLoc;
			*(Object::Vector2D*)&params[12] = InterpSpeedRange;
			*(Object::Vector2D*)&params[20] = InFocusFOV;
			*(float*)&params[28] = CameraFOV;
			*(bool*)&params[32] = bAlwaysFocus;
			*(bool*)&params[36] = bAdjustCamera;
			*(bool*)&params[40] = bIgnoreTrace;
			*(float*)&params[44] = FocusPitchOffsetDeg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFocusOnActor(class Actor* FocusActor, ScriptName FocusBoneName, Object::Vector2D InterpSpeedRange, Object::Vector2D InFocusFOV, float CameraFOV, bool bAlwaysFocus, bool bAdjustCamera, bool bIgnoreTrace, float FocusPitchOffsetDeg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.SetFocusOnActor");
			byte params[48] = { NULL };
			*(class Actor**)&params[0] = FocusActor;
			*(ScriptName*)&params[4] = FocusBoneName;
			*(Object::Vector2D*)&params[12] = InterpSpeedRange;
			*(Object::Vector2D*)&params[20] = InFocusFOV;
			*(float*)&params[28] = CameraFOV;
			*(bool*)&params[32] = bAlwaysFocus;
			*(bool*)&params[36] = bAdjustCamera;
			*(bool*)&params[40] = bIgnoreTrace;
			*(float*)&params[44] = FocusPitchOffsetDeg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* GetFocusActor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.GetFocusActor");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[0];
		}
		void ClearFocusPoint(bool bLeaveCameraRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.ClearFocusPoint");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bLeaveCameraRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateFocusPoint(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.UpdateFocusPoint");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector GetActualFocusLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.GetActualFocusLocation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		void AdjustFocusPointInterpolation(Object::Rotator Delta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.AdjustFocusPointInterpolation");
			byte params[12] = { NULL };
			*(Object::Rotator*)&params[0] = Delta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GameThirdPersonCameraMode* FindBestCameraMode(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.FindBestCameraMode");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GameThirdPersonCameraMode**)&params[4];
		}
		void ProcessViewRotation(float DeltaTime, class Actor* ViewTarget, Object::Rotator& out_ViewRotation, Object::Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.ProcessViewRotation");
			byte params[32] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(class Actor**)&params[4] = ViewTarget;
			*(Object::Rotator*)&params[8] = out_ViewRotation;
			*(Object::Rotator*)&params[20] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Object::Rotator*)&params[8];
			out_DeltaRot = *(Object::Rotator*)&params[20];
		}
		void OnBecomeActive(class GameCameraBase* OldCamera)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.OnBecomeActive");
			byte params[4] = { NULL };
			*(class GameCameraBase**)&params[0] = OldCamera;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ModifyPostProcessSettings(PostProcessVolume::PostProcessSettings& PP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.ModifyPostProcessSettings");
			byte params[220] = { NULL };
			*(PostProcessVolume::PostProcessSettings*)&params[0] = PP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PP = *(PostProcessVolume::PostProcessSettings*)&params[0];
		}
		void ResetInterpolation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameThirdPersonCamera.ResetInterpolation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
