#pragma once
#include "Core.Object.h"
#include "Core.Object.Vector.h"
#include "Engine.PostProcessVolume.PostProcessSettings.h"
#include "Engine.InterpGroupInst.h"
#include "Core.Object.Matrix.h"
#include "Engine.AnimNodeSequence.h"
#include "Engine.CameraAnim.h"
#include "Engine.InterpTrackInstMove.h"
#include "Engine.InterpTrackMove.h"
#include "Core.Object.Rotator.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CameraAnimInst." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.CameraAnimInst." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.CameraAnimInst." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CameraAnimInst : public Object
	{
	public:
		ADD_STRUCT(::VectorProperty, LastCameraLoc, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPPSettingsAlpha, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<PostProcessSettings>, LastPPSettings, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Matrix>, UserPlaySpaceMatrix, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PlaySpace, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodeSequence, SourceAnimNode)
		ADD_OBJECT(InterpTrackInstMove, MoveInst)
		ADD_OBJECT(InterpTrackMove, MoveTrack)
		ADD_VAR(::FloatProperty, RemainingTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentBlendWeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransientScaleModifier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BasePlayScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PlayRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurBlendInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendInTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBlendingOut, 0x10)
		ADD_VAR(::BoolProperty, bBlendingIn, 0x8)
		ADD_VAR(::BoolProperty, bAutoReleaseWhenFinished, 0x4)
		ADD_VAR(::BoolProperty, bFinished, 0x2)
		ADD_VAR(::BoolProperty, bLooping, 0x1)
		ADD_VAR(::FloatProperty, CurTime, 0xFFFFFFFF)
		ADD_OBJECT(InterpGroupInst, InterpGroupInst)
		ADD_OBJECT(CameraAnim, CamAnim)
		void SetPlaySpace(byte NewSpace, Rotator UserPlaySpace)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraAnimInst.SetPlaySpace");
			byte* params = (byte*)malloc(13);
			*params = NewSpace;
			*(Rotator*)(params + 4) = UserPlaySpace;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Play(class CameraAnim* Anim, class Actor* CamActor, float InRate, float InScale, float InBlendInTime, float InBlendOutTime, bool bInLoop, bool bRandomStartTime, float Duration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraAnimInst.Play");
			byte* params = (byte*)malloc(36);
			*(class CameraAnim**)params = Anim;
			*(class Actor**)(params + 4) = CamActor;
			*(float*)(params + 8) = InRate;
			*(float*)(params + 12) = InScale;
			*(float*)(params + 16) = InBlendInTime;
			*(float*)(params + 20) = InBlendOutTime;
			*(bool*)(params + 24) = bInLoop;
			*(bool*)(params + 28) = bRandomStartTime;
			*(float*)(params + 32) = Duration;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Update(float NewRate, float NewScale, float NewBlendInTime, float NewBlendOutTime, float NewDuration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraAnimInst.Update");
			byte* params = (byte*)malloc(20);
			*(float*)params = NewRate;
			*(float*)(params + 4) = NewScale;
			*(float*)(params + 8) = NewBlendInTime;
			*(float*)(params + 12) = NewBlendOutTime;
			*(float*)(params + 16) = NewDuration;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdvanceAnim(float DeltaTime, bool bJump)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraAnimInst.AdvanceAnim");
			byte* params = (byte*)malloc(8);
			*(float*)params = DeltaTime;
			*(bool*)(params + 4) = bJump;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Stop(bool bImmediate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraAnimInst.Stop");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bImmediate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ApplyTransientScaling(float Scalar)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraAnimInst.ApplyTransientScaling");
			byte* params = (byte*)malloc(4);
			*(float*)params = Scalar;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
