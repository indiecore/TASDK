#pragma once
#include "Engine__AnimNode.h"
#include "Engine__AnimSequence.h"
#include "Engine__CameraAnim.h"
#include "Engine__CameraAnimInst.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeSequence." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimNodeSequence." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNodeSequence : public AnimNode
	{
	public:
		ADD_OBJECT(AnimSequence, AnimSeq)
		ADD_VAR(::BoolProperty, bPlaying, 0x1)
		ADD_VAR(::FloatProperty, Rate, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLooping, 0x2)
		ADD_VAR(::NameProperty, AnimSeqName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCauseActorAnimEnd, 0x4)
		ADD_VAR(::BoolProperty, bCauseActorAnimPlay, 0x8)
		ADD_VAR(::BoolProperty, bZeroRootRotation, 0x10)
		ADD_VAR(::BoolProperty, bZeroRootTranslation, 0x20)
		ADD_VAR(::BoolProperty, bDisableWarningWhenAnimNotFound, 0x40)
		ADD_VAR(::BoolProperty, bNoNotifies, 0x80)
		ADD_VAR(::BoolProperty, bForceRefposeWhenNotPlaying, 0x100)
		ADD_VAR(::BoolProperty, bIsIssuingNotifies, 0x200)
		ADD_VAR(::BoolProperty, m_bSuppressNotifies, 0x400)
		ADD_VAR(::BoolProperty, bForceAlwaysSlave, 0x800)
		ADD_VAR(::BoolProperty, bSynchronize, 0x1000)
		ADD_VAR(::BoolProperty, bReverseSync, 0x2000)
		ADD_VAR(::BoolProperty, bShowTimeLineSlider, 0x4000)
		ADD_VAR(::BoolProperty, bLoopCameraAnim, 0x8000)
		ADD_VAR(::BoolProperty, bRandomizeCameraAnimLoopStartTime, 0x10000)
		ADD_VAR(::BoolProperty, bEditorOnlyAddRefPoseToAdditiveAnimation, 0x20000)
		ADD_VAR(::FloatProperty, CurrentTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PreviousTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EndTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AnimLinkupIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NotifyWeightThreshold, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SynchGroupName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SynchPosOffset, 0xFFFFFFFF)
		ADD_OBJECT(CameraAnim, CameraAnim)
		ADD_OBJECT(CameraAnimInst, ActiveCameraAnimInstance)
		ADD_VAR(::FloatProperty, CameraAnimScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraAnimPlayRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraAnimBlendInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraAnimBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RootBoneOption, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RootRotationOption, 0xFFFFFFFF)
		void SetAnim(ScriptName Sequence)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequence.SetAnim");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = Sequence;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayAnim(bool bLoop, float InRate, float StartTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequence.PlayAnim");
			byte* params = (byte*)malloc(12);
			*(bool*)params = bLoop;
			*(float*)(params + 4) = InRate;
			*(float*)(params + 8) = StartTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequence.StopAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplayAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequence.ReplayAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPosition(float NewTime, bool bFireNotifies)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequence.SetPosition");
			byte* params = (byte*)malloc(8);
			*(float*)params = NewTime;
			*(bool*)(params + 4) = bFireNotifies;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetNormalizedPosition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequence.GetNormalizedPosition");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float FindGroupRelativePosition(float GroupRelativePosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequence.FindGroupRelativePosition");
			byte* params = (byte*)malloc(8);
			*(float*)params = GroupRelativePosition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float FindGroupPosition(float GroupRelativePosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequence.FindGroupPosition");
			byte* params = (byte*)malloc(8);
			*(float*)params = GroupRelativePosition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float GetGroupRelativePosition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequence.GetGroupRelativePosition");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetGlobalPlayRate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequence.GetGlobalPlayRate");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetAnimPlaybackLength()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequence.GetAnimPlaybackLength");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetTimeLeft()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequence.GetTimeLeft");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void SetRootBoneAxisOption(byte AxisX, byte AxisY, byte AxisZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequence.SetRootBoneAxisOption");
			byte* params = (byte*)malloc(3);
			*params = AxisX;
			*(params + 1) = AxisY;
			*(params + 2) = AxisZ;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRootBoneRotationOption(byte AxisX, byte AxisY, byte AxisZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequence.SetRootBoneRotationOption");
			byte* params = (byte*)malloc(3);
			*params = AxisX;
			*(params + 1) = AxisY;
			*(params + 2) = AxisZ;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
