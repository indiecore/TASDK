#pragma once
#include "Engine.CameraAnimInst.h"
#include "Engine.AnimNode.h"
#include "Engine.AnimSequence.h"
#include "Engine.CameraAnim.h"
#include "Engine.SkelControlBase.h"
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
	class AnimNodeSequence : public AnimNode
	{
	public:
		enum ERootRotationOption : byte
		{
			RRO_Default = 0,
			RRO_Discard = 1,
			RRO_Extract = 2,
			RRO_MAX = 3,
		};
		enum ERootBoneAxis : byte
		{
			RBA_Default = 0,
			RBA_Discard = 1,
			RBA_Translate = 2,
			RBA_MAX = 3,
		};
		ADD_OBJECT(AnimSequence, AnimSeq, 252)
		ADD_BOOL(bPlaying, 236, 0x1)
		ADD_STRUCT(float, Rate, 232)
		ADD_BOOL(bLooping, 236, 0x2)
		ADD_STRUCT(ScriptName, AnimSeqName, 224)
		ADD_BOOL(bCauseActorAnimEnd, 236, 0x4)
		ADD_BOOL(bCauseActorAnimPlay, 236, 0x8)
		ADD_BOOL(bZeroRootRotation, 236, 0x10)
		ADD_BOOL(bZeroRootTranslation, 236, 0x20)
		ADD_BOOL(bDisableWarningWhenAnimNotFound, 236, 0x40)
		ADD_BOOL(bNoNotifies, 236, 0x80)
		ADD_BOOL(bForceRefposeWhenNotPlaying, 236, 0x100)
		ADD_BOOL(bIsIssuingNotifies, 236, 0x200)
		ADD_BOOL(m_bSuppressNotifies, 236, 0x400)
		ADD_BOOL(bForceAlwaysSlave, 236, 0x800)
		ADD_BOOL(bSynchronize, 236, 0x1000)
		ADD_BOOL(bReverseSync, 236, 0x2000)
		ADD_BOOL(bShowTimeLineSlider, 236, 0x4000)
		ADD_BOOL(bLoopCameraAnim, 236, 0x8000)
		ADD_BOOL(bRandomizeCameraAnimLoopStartTime, 236, 0x10000)
		ADD_BOOL(bEditorOnlyAddRefPoseToAdditiveAnimation, 236, 0x20000)
		ADD_STRUCT(float, CurrentTime, 240)
		ADD_STRUCT(float, PreviousTime, 244)
		ADD_STRUCT(float, EndTime, 248)
		ADD_STRUCT(int, AnimLinkupIndex, 256)
		ADD_STRUCT(float, NotifyWeightThreshold, 260)
		ADD_STRUCT(ScriptName, SynchGroupName, 264)
		ADD_STRUCT(float, SynchPosOffset, 272)
		ADD_OBJECT(CameraAnim, CameraAnim, 276)
		ADD_OBJECT(CameraAnimInst, ActiveCameraAnimInstance, 280)
		ADD_STRUCT(float, CameraAnimScale, 284)
		ADD_STRUCT(float, CameraAnimPlayRate, 288)
		ADD_STRUCT(float, CameraAnimBlendInTime, 292)
		ADD_STRUCT(float, CameraAnimBlendOutTime, 296)
		ADD_STRUCT(AnimNodeSequence::ERootBoneAxis, RootBoneOption, 300)
		ADD_STRUCT(AnimNodeSequence::ERootRotationOption, RootRotationOption, 303)
		ADD_STRUCT(ScriptArray<class SkelControlBase*>, MetaDataSkelControlList, 308)
		void SetAnim(ScriptName Sequence)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10909);
			byte params[8] = { NULL };
			*(ScriptName*)params = Sequence;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayAnim(bool bLoop, float InRate, float StartTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10911);
			byte params[12] = { NULL };
			*(bool*)params = bLoop;
			*(float*)&params[4] = InRate;
			*(float*)&params[8] = StartTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10915);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplayAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10916);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPosition(float NewTime, bool bFireNotifies)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10917);
			byte params[8] = { NULL };
			*(float*)params = NewTime;
			*(bool*)&params[4] = bFireNotifies;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetNormalizedPosition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10920);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float FindGroupRelativePosition(float GroupRelativePosition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10922);
			byte params[8] = { NULL };
			*(float*)params = GroupRelativePosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float FindGroupPosition(float GroupRelativePosition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10925);
			byte params[8] = { NULL };
			*(float*)params = GroupRelativePosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float GetGroupRelativePosition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10928);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetGlobalPlayRate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10930);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetAnimPlaybackLength()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10932);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetTimeLeft()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10934);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void SetRootBoneAxisOption(AnimNodeSequence::ERootBoneAxis AxisX, AnimNodeSequence::ERootBoneAxis AxisY, AnimNodeSequence::ERootBoneAxis AxisZ)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10936);
			byte params[3] = { NULL };
			*(AnimNodeSequence::ERootBoneAxis*)params = AxisX;
			*(AnimNodeSequence::ERootBoneAxis*)&params[1] = AxisY;
			*(AnimNodeSequence::ERootBoneAxis*)&params[2] = AxisZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRootBoneRotationOption(AnimNodeSequence::ERootRotationOption AxisX, AnimNodeSequence::ERootRotationOption AxisY, AnimNodeSequence::ERootRotationOption AxisZ)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10941);
			byte params[3] = { NULL };
			*(AnimNodeSequence::ERootRotationOption*)params = AxisX;
			*(AnimNodeSequence::ERootRotationOption*)&params[1] = AxisY;
			*(AnimNodeSequence::ERootRotationOption*)&params[2] = AxisZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
