#pragma once
#include "Engine__Actor.h"
#include "Engine__CameraModifier_CameraShake.h"
#include "Engine__HUD.h"
#include "Engine__CameraAnimInst.h"
#include "Engine__DynamicCameraActor.h"
#include "Engine__CameraShake.h"
#include "Engine__CameraModifier.h"
#include "Engine__EmitterCameraLensEffectBase.h"
#include "Engine__PlayerController.h"
#include "Engine__CameraAnim.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Camera." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Camera." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Camera." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Camera : public Actor
	{
	public:
		ADD_OBJECT(CameraModifier_CameraShake, CameraShakeCamMod)
		ADD_OBJECT(ScriptClass, CameraShakeCamModClass)
		ADD_OBJECT(CameraAnimInst, AnimInstPool)
		ADD_OBJECT(DynamicCameraActor, AnimCameraActor)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TCameraCache' for the property named 'CameraCache'!
		ADD_VAR(::FloatProperty, DefaultFOV, 0xFFFFFFFF)
		ADD_OBJECT(PlayerController, PCOwner)
		ADD_VAR(::BoolProperty, bLockedFOV, 0x1)
		ADD_VAR(::FloatProperty, LockedFOV, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableColorScaling, 0x8)
		ADD_STRUCT(::VectorProperty, ColorScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, OriginalColorScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, DesiredColorScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ColorScaleInterpStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ColorScaleInterpDuration, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableColorScaleInterp, 0x10)
		ADD_VAR(::BoolProperty, bConstrainAspectRatio, 0x2)
		ADD_VAR(::FloatProperty, CamOverridePostProcessAlpha, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget' for the property named 'PendingViewTarget'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.ViewTargetTransitionParams' for the property named 'BlendParams'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget' for the property named 'ViewTarget'!
		ADD_VAR(::FloatProperty, ConstrainedAspectRatio, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendTimeToGo, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableFading, 0x4)
		ADD_VAR(::FloatProperty, FadeTimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeAmount, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'FadeAlpha'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TCameraCache' for the property named 'LastFrameCameraCache'!
		ADD_STRUCT(::VectorProperty, FreeCamOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FreeCamDistance, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.PostProcessVolume.PostProcessSettings' for the property named 'CamPostProcessSettings'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'FadeColor'!
		ADD_VAR(::FloatProperty, OffAxisPitchAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OffAxisYawAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DefaultAspectRatio, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, CameraStyle, 0xFFFFFFFF)
		class CameraModifier* CreateCameraModifier(ScriptClass* ModifierClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.CreateCameraModifier");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = ModifierClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class CameraModifier**)(params + 4);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyCameraModifiers(float DeltaTime, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.TPOV'!
void*& OutPOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.ApplyCameraModifiers");
			byte* params = (byte*)malloc(32);
			*(float*)params = DeltaTime;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.TPOV'!
void**)(params + 4) = OutPOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutPOV = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.TPOV'!
void**)(params + 4);
			free(params);
		}
		void InitializeFor(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.InitializeFor");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetViewTarget(class Actor* NewViewTarget, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.ViewTargetTransitionParams'!
void* TransitionParams)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.SetViewTarget");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = NewViewTarget;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.ViewTargetTransitionParams'!
void**)(params + 4) = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetFOVAngle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.GetFOVAngle");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void SetFOV(float NewFOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.SetFOV");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewFOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetCameraViewPoint(Vector& OutCamLoc, Rotator& OutCamRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.GetCameraViewPoint");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = OutCamLoc;
			*(Rotator*)(params + 12) = OutCamRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutCamLoc = *(Vector*)params;
			OutCamRot = *(Rotator*)(params + 12);
			free(params);
		}
		Rotator GetCameraRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.GetCameraRotation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)params;
			free(params);
			return returnVal;
		}
		void SetDesiredColorScale(Vector NewColorScale, float InterpTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.SetDesiredColorScale");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = NewColorScale;
			*(float*)(params + 12) = InterpTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateCamera(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.UpdateCamera");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.TPOV'!
void* BlendViewTargets(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void*& A, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void*& B, float Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.BlendViewTargets");
			byte* params = (byte*)malloc(120);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)(params + 44) = B;
			*(float*)(params + 88) = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)params;
			B = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)(params + 44);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.TPOV'!
void**)(params + 92);
			free(params);
			return returnVal;
		}
		void FillCameraCache(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.TPOV'!
void*& NewPOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.FillCameraCache");
			byte* params = (byte*)malloc(28);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.TPOV'!
void**)params = NewPOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			NewPOV = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.TPOV'!
void**)params;
			free(params);
		}
		void CheckViewTarget(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void*& VT)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.CheckViewTarget");
			byte* params = (byte*)malloc(44);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)params = VT;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			VT = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)params;
			free(params);
		}
		void UpdateViewTarget(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void*& OutVT, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.UpdateViewTarget");
			byte* params = (byte*)malloc(48);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)params = OutVT;
			*(float*)(params + 44) = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutVT = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)params;
			free(params);
		}
		void ProcessViewRotation(float DeltaTime, Rotator& OutViewRotation, Rotator& OutDeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.ProcessViewRotation");
			byte* params = (byte*)malloc(28);
			*(float*)params = DeltaTime;
			*(Rotator*)(params + 4) = OutViewRotation;
			*(Rotator*)(params + 16) = OutDeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutViewRotation = *(Rotator*)(params + 4);
			OutDeltaRot = *(Rotator*)(params + 16);
			free(params);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		class EmitterCameraLensEffectBase* FindCameraLensEffect(ScriptClass* LensEffectEmitterClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.FindCameraLensEffect");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = LensEffectEmitterClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class EmitterCameraLensEffectBase**)(params + 4);
			free(params);
			return returnVal;
		}
		void AddCameraLensEffect(ScriptClass* LensEffectEmitterClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.AddCameraLensEffect");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = LensEffectEmitterClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveCameraLensEffect(class EmitterCameraLensEffectBase* Emitter)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.RemoveCameraLensEffect");
			byte* params = (byte*)malloc(4);
			*(class EmitterCameraLensEffectBase**)params = Emitter;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearCameraLensEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.ClearCameraLensEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayCameraShake(class CameraShake* Shake, float Scale, byte PlaySpace, Rotator UserPlaySpaceRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.PlayCameraShake");
			byte* params = (byte*)malloc(21);
			*(class CameraShake**)params = Shake;
			*(float*)(params + 4) = Scale;
			*(params + 8) = PlaySpace;
			*(Rotator*)(params + 12) = UserPlaySpaceRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopCameraShake(class CameraShake* Shake)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.StopCameraShake");
			byte* params = (byte*)malloc(4);
			*(class CameraShake**)params = Shake;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float CalcRadialShakeScale(class Camera* Cam, Vector Epicenter, float InnerRadius, float OuterRadius, float Falloff)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.CalcRadialShakeScale");
			byte* params = (byte*)malloc(32);
			*(class Camera**)params = Cam;
			*(Vector*)(params + 4) = Epicenter;
			*(float*)(params + 16) = InnerRadius;
			*(float*)(params + 20) = OuterRadius;
			*(float*)(params + 24) = Falloff;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 28);
			free(params);
			return returnVal;
		}
		void PlayWorldCameraShake(class CameraShake* Shake, class Actor* ShakeInstigator, Vector Epicenter, float InnerRadius, float OuterRadius, float Falloff, bool bTryForceFeedback, bool bOrientShakeTowardsEpicenter)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.PlayWorldCameraShake");
			byte* params = (byte*)malloc(40);
			*(class CameraShake**)params = Shake;
			*(class Actor**)(params + 4) = ShakeInstigator;
			*(Vector*)(params + 8) = Epicenter;
			*(float*)(params + 20) = InnerRadius;
			*(float*)(params + 24) = OuterRadius;
			*(float*)(params + 28) = Falloff;
			*(bool*)(params + 32) = bTryForceFeedback;
			*(bool*)(params + 36) = bOrientShakeTowardsEpicenter;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearAllCameraShakes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.ClearAllCameraShakes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class CameraAnimInst* PlayCameraAnim(class CameraAnim* Anim, float Rate, float Scale, float BlendInTime, float BlendOutTime, bool bLoop, bool bRandomStartTime, float Duration, bool bSingleInstance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.PlayCameraAnim");
			byte* params = (byte*)malloc(40);
			*(class CameraAnim**)params = Anim;
			*(float*)(params + 4) = Rate;
			*(float*)(params + 8) = Scale;
			*(float*)(params + 12) = BlendInTime;
			*(float*)(params + 16) = BlendOutTime;
			*(bool*)(params + 20) = bLoop;
			*(bool*)(params + 24) = bRandomStartTime;
			*(float*)(params + 28) = Duration;
			*(bool*)(params + 32) = bSingleInstance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class CameraAnimInst**)(params + 36);
			free(params);
			return returnVal;
		}
		void StopAllCameraAnims(bool bImmediate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.StopAllCameraAnims");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bImmediate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopAllCameraAnimsByType(class CameraAnim* Anim, bool bImmediate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.StopAllCameraAnimsByType");
			byte* params = (byte*)malloc(8);
			*(class CameraAnim**)params = Anim;
			*(bool*)(params + 4) = bImmediate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopCameraAnim(class CameraAnimInst* AnimInst, bool bImmediate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Camera.StopCameraAnim");
			byte* params = (byte*)malloc(8);
			*(class CameraAnimInst**)params = AnimInst;
			*(bool*)(params + 4) = bImmediate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
