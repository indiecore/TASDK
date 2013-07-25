#pragma once
#include "Engine__AnimNodeBlendBase.h"
#include "Engine__AnimNodeSynch.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeSlot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimNodeSlot." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNodeSlot : public AnimNodeBlendBase
	{
	public:
		ADD_OBJECT(AnimNodeSynch, SynchNode)
		ADD_VAR(::FloatProperty, BlendTimeToGo, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TargetChildIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CustomChildIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PendingBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAdditiveAnimationsOverrideSource, 0x8)
		ADD_VAR(::BoolProperty, bSkipBlendWhenNotRendered, 0x4)
		ADD_VAR(::BoolProperty, bEarlyAnimEndNotify, 0x2)
		ADD_VAR(::BoolProperty, bIsPlayingCustomAnim, 0x1)
		float PlayCustomAnim(ScriptName AnimName, float Rate, float BlendInTime, float BlendOutTime, bool bLooping, bool bOverride, float StartTime, float EndTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.PlayCustomAnim");
			byte* params = (byte*)malloc(40);
			*(ScriptName*)params = AnimName;
			*(float*)(params + 8) = Rate;
			*(float*)(params + 12) = BlendInTime;
			*(float*)(params + 16) = BlendOutTime;
			*(bool*)(params + 20) = bLooping;
			*(bool*)(params + 24) = bOverride;
			*(float*)(params + 28) = StartTime;
			*(float*)(params + 32) = EndTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 36);
			free(params);
			return returnVal;
		}
		bool PlayCustomAnimByDuration(ScriptName AnimName, float Duration, float BlendInTime, float BlendOutTime, bool bLooping, bool bOverride)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.PlayCustomAnimByDuration");
			byte* params = (byte*)malloc(32);
			*(ScriptName*)params = AnimName;
			*(float*)(params + 8) = Duration;
			*(float*)(params + 12) = BlendInTime;
			*(float*)(params + 16) = BlendOutTime;
			*(bool*)(params + 20) = bLooping;
			*(bool*)(params + 24) = bOverride;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		ScriptName GetPlayedAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.GetPlayedAnimation");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
		void StopCustomAnim(float BlendOutTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.StopCustomAnim");
			byte* params = (byte*)malloc(4);
			*(float*)params = BlendOutTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCustomAnim(ScriptName AnimName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.SetCustomAnim");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = AnimName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetActorAnimEndNotification(bool bNewStatus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.SetActorAnimEndNotification");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewStatus;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class AnimNodeSequence* GetCustomAnimNodeSeq()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.GetCustomAnimNodeSeq");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class AnimNodeSequence**)params;
			free(params);
			return returnVal;
		}
		void SetRootBoneAxisOption(byte AxisX, byte AxisY, byte AxisZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.SetRootBoneAxisOption");
			byte* params = (byte*)malloc(3);
			*params = AxisX;
			*(params + 1) = AxisY;
			*(params + 2) = AxisZ;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRootBoneRotationOption(byte AxisX, byte AxisY, byte AxisZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.SetRootBoneRotationOption");
			byte* params = (byte*)malloc(3);
			*params = AxisX;
			*(params + 1) = AxisY;
			*(params + 2) = AxisZ;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddToSynchGroup(ScriptName GroupName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSlot.AddToSynchGroup");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
