#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.EmitterCameraLensEffectBase.h"
#include "Engine.HUD.h"
#include "Engine.CameraModifier_CameraShake.h"
#include "Engine.CameraAnimInst.h"
#include "Engine.DynamicCameraActor.h"
#include "Engine.CameraModifier.h"
#include "Engine.PostProcessVolume.h"
#include "Engine.PlayerController.h"
#include "Engine.CameraShake.h"
#include "Engine.CameraAnim.h"
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
	class Camera : public Actor
	{
	public:
		static const auto MAX_ACTIVE_CAMERA_ANIMS = 8;
		enum EViewTargetBlendFunction : byte
		{
			VTBlend_Linear = 0,
			VTBlend_Cubic = 1,
			VTBlend_EaseIn = 2,
			VTBlend_EaseOut = 3,
			VTBlend_EaseInOut = 4,
			VTBlend_MAX = 5,
		};
		enum ECameraAnimPlaySpace : byte
		{
			CAPS_CameraLocal = 0,
			CAPS_World = 1,
			CAPS_UserDefined = 2,
			CAPS_MAX = 3,
		};
		struct TViewTarget
		{
		public:
			ADD_OBJECT(Actor, Target, 0)
			ADD_STRUCT(Object::TPOV, POV, 8)
			ADD_STRUCT(float, AspectRatio, 36)
			ADD_OBJECT(Controller, Controller, 4)
			ADD_OBJECT(PlayerReplicationInfo, PRI, 40)
		};
		struct TCameraCache
		{
		public:
			ADD_STRUCT(Object::TPOV, POV, 4)
			ADD_STRUCT(float, TimeStamp, 0)
		};
		struct ViewTargetTransitionParams
		{
		public:
			ADD_BOOL(bLockOutgoing, 12, 0x1)
			ADD_STRUCT(float, BlendTime, 0)
			ADD_STRUCT(Camera::EViewTargetBlendFunction, BlendFunction, 4)
			ADD_STRUCT(float, BlendExp, 8)
		};
		ADD_OBJECT(CameraModifier_CameraShake, CameraShakeCamMod, 1020)
		ADD_OBJECT(ScriptClass, CameraShakeCamModClass, 1024)
		ADD_OBJECT(CameraAnimInst, AnimInstPool, 1028)
		ADD_STRUCT(ScriptArray<class CameraAnimInst*>, FreeAnims, 1072)
		ADD_OBJECT(DynamicCameraActor, AnimCameraActor, 1084)
		ADD_STRUCT(Camera::TCameraCache, CameraCache, 792)
		ADD_STRUCT(float, DefaultFOV, 488)
		ADD_OBJECT(PlayerController, PCOwner, 476)
		ADD_BOOL(bLockedFOV, 492, 0x1)
		ADD_STRUCT(float, LockedFOV, 496)
		ADD_BOOL(bEnableColorScaling, 492, 0x8)
		ADD_STRUCT(Vector, ColorScale, 748)
		ADD_STRUCT(Vector, OriginalColorScale, 772)
		ADD_STRUCT(Vector, DesiredColorScale, 760)
		ADD_STRUCT(float, ColorScaleInterpStartTime, 788)
		ADD_STRUCT(float, ColorScaleInterpDuration, 784)
		ADD_BOOL(bEnableColorScaleInterp, 492, 0x10)
		ADD_BOOL(bConstrainAspectRatio, 492, 0x2)
		ADD_STRUCT(float, CamOverridePostProcessAlpha, 524)
		ADD_STRUCT(Camera::TViewTarget, PendingViewTarget, 900)
		ADD_STRUCT(Camera::ViewTargetTransitionParams, BlendParams, 948)
		ADD_STRUCT(Camera::TViewTarget, ViewTarget, 856)
		ADD_STRUCT(float, ConstrainedAspectRatio, 500)
		ADD_STRUCT(float, BlendTimeToGo, 944)
		ADD_BOOL(bEnableFading, 492, 0x4)
		ADD_STRUCT(float, FadeTimeRemaining, 1004)
		ADD_STRUCT(float, FadeTime, 1000)
		ADD_STRUCT(float, FadeAmount, 520)
		ADD_STRUCT(Object::Vector2D, FadeAlpha, 992)
		ADD_STRUCT(Camera::TCameraCache, LastFrameCameraCache, 824)
		ADD_STRUCT(ScriptArray<class CameraModifier*>, ModifierList, 964)
		ADD_STRUCT(ScriptArray<class EmitterCameraLensEffectBase*>, CameraLensEffects, 1008)
		ADD_STRUCT(ScriptArray<class CameraAnimInst*>, ActiveAnims, 1060)
		ADD_STRUCT(Vector, FreeCamOffset, 980)
		ADD_STRUCT(float, FreeCamDistance, 976)
		ADD_STRUCT(PostProcessVolume::PostProcessSettings, CamPostProcessSettings, 528)
		ADD_STRUCT(Object::Color, FadeColor, 516)
		ADD_STRUCT(float, OffAxisPitchAngle, 512)
		ADD_STRUCT(float, OffAxisYawAngle, 508)
		ADD_STRUCT(float, DefaultAspectRatio, 504)
		ADD_STRUCT(ScriptName, CameraStyle, 480)
		class CameraModifier* CreateCameraModifier(ScriptClass* ModifierClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6404);
			byte params[8] = { NULL };
			*(ScriptClass**)params = ModifierClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class CameraModifier**)&params[4];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6410);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6417);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyCameraModifiers(float DeltaTime, Object::TPOV& OutPOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6418);
			byte params[32] = { NULL };
			*(float*)params = DeltaTime;
			*(Object::TPOV*)&params[4] = OutPOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutPOV = *(Object::TPOV*)&params[4];
		}
		void InitializeFor(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6421);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetViewTarget(class Actor* NewViewTarget, Camera::ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6428);
			byte params[20] = { NULL };
			*(class Actor**)params = NewViewTarget;
			*(Camera::ViewTargetTransitionParams*)&params[4] = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetFOVAngle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6431);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void SetFOV(float NewFOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6435);
			byte params[4] = { NULL };
			*(float*)params = NewFOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetCameraViewPoint(Vector& OutCamLoc, Rotator& OutCamRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6437);
			byte params[24] = { NULL };
			*(Vector*)params = OutCamLoc;
			*(Rotator*)&params[12] = OutCamRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutCamLoc = *(Vector*)params;
			OutCamRot = *(Rotator*)&params[12];
		}
		Rotator GetCameraRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6440);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)params;
		}
		void SetDesiredColorScale(Vector NewColorScale, float InterpTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6442);
			byte params[16] = { NULL };
			*(Vector*)params = NewColorScale;
			*(float*)&params[12] = InterpTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateCamera(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6452);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::TPOV BlendViewTargets(Camera::TViewTarget& A, Camera::TViewTarget& B, float Alpha)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6472);
			byte params[120] = { NULL };
			*(Camera::TViewTarget*)params = A;
			*(Camera::TViewTarget*)&params[44] = B;
			*(float*)&params[88] = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Camera::TViewTarget*)params;
			B = *(Camera::TViewTarget*)&params[44];
			return *(Object::TPOV*)&params[92];
		}
		void FillCameraCache(Object::TPOV& NewPOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6474);
			byte params[28] = { NULL };
			*(Object::TPOV*)params = NewPOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewPOV = *(Object::TPOV*)params;
		}
		void CheckViewTarget(Camera::TViewTarget& VT)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6489);
			byte params[44] = { NULL };
			*(Camera::TViewTarget*)params = VT;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			VT = *(Camera::TViewTarget*)params;
		}
		void UpdateViewTarget(Camera::TViewTarget& OutVT, float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6593);
			byte params[48] = { NULL };
			*(Camera::TViewTarget*)params = OutVT;
			*(float*)&params[44] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutVT = *(Camera::TViewTarget*)params;
		}
		void ProcessViewRotation(float DeltaTime, Rotator& OutViewRotation, Rotator& OutDeltaRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6613);
			byte params[28] = { NULL };
			*(float*)params = DeltaTime;
			*(Rotator*)&params[4] = OutViewRotation;
			*(Rotator*)&params[16] = OutDeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutViewRotation = *(Rotator*)&params[4];
			OutDeltaRot = *(Rotator*)&params[16];
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6620);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		class EmitterCameraLensEffectBase* FindCameraLensEffect(ScriptClass* LensEffectEmitterClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6627);
			byte params[8] = { NULL };
			*(ScriptClass**)params = LensEffectEmitterClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class EmitterCameraLensEffectBase**)&params[4];
		}
		void AddCameraLensEffect(ScriptClass* LensEffectEmitterClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6632);
			byte params[4] = { NULL };
			*(ScriptClass**)params = LensEffectEmitterClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveCameraLensEffect(class EmitterCameraLensEffectBase* Emitter)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6640);
			byte params[4] = { NULL };
			*(class EmitterCameraLensEffectBase**)params = Emitter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearCameraLensEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6642);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayCameraShake(class CameraShake* Shake, float Scale, Camera::ECameraAnimPlaySpace PlaySpace, Rotator UserPlaySpaceRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6644);
			byte params[21] = { NULL };
			*(class CameraShake**)params = Shake;
			*(float*)&params[4] = Scale;
			*(Camera::ECameraAnimPlaySpace*)&params[8] = PlaySpace;
			*(Rotator*)&params[12] = UserPlaySpaceRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopCameraShake(class CameraShake* Shake)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6649);
			byte params[4] = { NULL };
			*(class CameraShake**)params = Shake;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float CalcRadialShakeScale(class Camera* Cam, Vector Epicenter, float InnerRadius, float OuterRadius, float Falloff)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6651);
			byte params[32] = { NULL };
			*(class Camera**)params = Cam;
			*(Vector*)&params[4] = Epicenter;
			*(float*)&params[16] = InnerRadius;
			*(float*)&params[20] = OuterRadius;
			*(float*)&params[24] = Falloff;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[28];
		}
		void PlayWorldCameraShake(class CameraShake* Shake, class Actor* ShakeInstigator, Vector Epicenter, float InnerRadius, float OuterRadius, float Falloff, bool bTryForceFeedback, bool bOrientShakeTowardsEpicenter)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6660);
			byte params[40] = { NULL };
			*(class CameraShake**)params = Shake;
			*(class Actor**)&params[4] = ShakeInstigator;
			*(Vector*)&params[8] = Epicenter;
			*(float*)&params[20] = InnerRadius;
			*(float*)&params[24] = OuterRadius;
			*(float*)&params[28] = Falloff;
			*(bool*)&params[32] = bTryForceFeedback;
			*(bool*)&params[36] = bOrientShakeTowardsEpicenter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearAllCameraShakes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6674);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class CameraAnimInst* PlayCameraAnim(class CameraAnim* Anim, float Rate, float Scale, float BlendInTime, float BlendOutTime, bool bLoop, bool bRandomStartTime, float Duration, bool bSingleInstance)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6675);
			byte params[40] = { NULL };
			*(class CameraAnim**)params = Anim;
			*(float*)&params[4] = Rate;
			*(float*)&params[8] = Scale;
			*(float*)&params[12] = BlendInTime;
			*(float*)&params[16] = BlendOutTime;
			*(bool*)&params[20] = bLoop;
			*(bool*)&params[24] = bRandomStartTime;
			*(float*)&params[28] = Duration;
			*(bool*)&params[32] = bSingleInstance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class CameraAnimInst**)&params[36];
		}
		void StopAllCameraAnims(bool bImmediate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6686);
			byte params[4] = { NULL };
			*(bool*)params = bImmediate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopAllCameraAnimsByType(class CameraAnim* Anim, bool bImmediate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6688);
			byte params[8] = { NULL };
			*(class CameraAnim**)params = Anim;
			*(bool*)&params[4] = bImmediate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopCameraAnim(class CameraAnimInst* AnimInst, bool bImmediate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6691);
			byte params[8] = { NULL };
			*(class CameraAnimInst**)params = AnimInst;
			*(bool*)&params[4] = bImmediate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
