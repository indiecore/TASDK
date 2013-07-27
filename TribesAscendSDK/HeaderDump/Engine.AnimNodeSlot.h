#pragma once
#include "Engine.AnimNodeBlendBase.h"
#include "Engine.AnimNodeSynch.h"
#include "Engine.AnimNodeSequence.h"
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
	class AnimNodeSlot : public AnimNodeBlendBase
	{
	public:
		ADD_STRUCT(ScriptArray<float>, TargetWeight, 260)
		ADD_OBJECT(AnimNodeSynch, SynchNode, 276)
		ADD_STRUCT(float, BlendTimeToGo, 272)
		ADD_STRUCT(int, TargetChildIndex, 256)
		ADD_STRUCT(int, CustomChildIndex, 252)
		ADD_STRUCT(float, PendingBlendOutTime, 248)
		ADD_BOOL(bAdditiveAnimationsOverrideSource, 244, 0x8)
		ADD_BOOL(bSkipBlendWhenNotRendered, 244, 0x4)
		ADD_BOOL(bEarlyAnimEndNotify, 244, 0x2)
		ADD_BOOL(bIsPlayingCustomAnim, 244, 0x1)
		float PlayCustomAnim(ScriptName AnimName, float Rate, float BlendInTime, float BlendOutTime, bool bLooping, bool bOverride, float StartTime, float EndTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.PlayCustomAnim");
			byte params[40] = { NULL };
			*(ScriptName*)&params[0] = AnimName;
			*(float*)&params[8] = Rate;
			*(float*)&params[12] = BlendInTime;
			*(float*)&params[16] = BlendOutTime;
			*(bool*)&params[20] = bLooping;
			*(bool*)&params[24] = bOverride;
			*(float*)&params[28] = StartTime;
			*(float*)&params[32] = EndTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[36];
		}
		bool PlayCustomAnimByDuration(ScriptName AnimName, float Duration, float BlendInTime, float BlendOutTime, bool bLooping, bool bOverride)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.PlayCustomAnimByDuration");
			byte params[32] = { NULL };
			*(ScriptName*)&params[0] = AnimName;
			*(float*)&params[8] = Duration;
			*(float*)&params[12] = BlendInTime;
			*(float*)&params[16] = BlendOutTime;
			*(bool*)&params[20] = bLooping;
			*(bool*)&params[24] = bOverride;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		ScriptName GetPlayedAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.GetPlayedAnimation");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[0];
		}
		void StopCustomAnim(float BlendOutTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.StopCustomAnim");
			byte params[4] = { NULL };
			*(float*)&params[0] = BlendOutTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCustomAnim(ScriptName AnimName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.SetCustomAnim");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = AnimName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActorAnimEndNotification(bool bNewStatus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.SetActorAnimEndNotification");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewStatus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class AnimNodeSequence* GetCustomAnimNodeSeq()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.GetCustomAnimNodeSeq");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AnimNodeSequence**)&params[0];
		}
		void SetRootBoneAxisOption(AnimNodeSequence::ERootBoneAxis AxisX, AnimNodeSequence::ERootBoneAxis AxisY, AnimNodeSequence::ERootBoneAxis AxisZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.SetRootBoneAxisOption");
			byte params[3] = { NULL };
			*(AnimNodeSequence::ERootBoneAxis*)&params[0] = AxisX;
			*(AnimNodeSequence::ERootBoneAxis*)&params[1] = AxisY;
			*(AnimNodeSequence::ERootBoneAxis*)&params[2] = AxisZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRootBoneRotationOption(AnimNodeSequence::ERootRotationOption AxisX, AnimNodeSequence::ERootRotationOption AxisY, AnimNodeSequence::ERootRotationOption AxisZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.SetRootBoneRotationOption");
			byte params[3] = { NULL };
			*(AnimNodeSequence::ERootRotationOption*)&params[0] = AxisX;
			*(AnimNodeSequence::ERootRotationOption*)&params[1] = AxisY;
			*(AnimNodeSequence::ERootRotationOption*)&params[2] = AxisZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddToSynchGroup(ScriptName GroupName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.AddToSynchGroup");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
