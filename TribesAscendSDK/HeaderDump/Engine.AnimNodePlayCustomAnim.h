#pragma once
#include "Engine.AnimNodeBlend.h"
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
namespace UnrealScript
{
	class AnimNodePlayCustomAnim : public AnimNodeBlend
	{
	public:
		ADD_STRUCT(float, CustomPendingBlendOutTime, 264)
		ADD_BOOL(bIsPlayingCustomAnim, 260, 0x1)
		float PlayCustomAnim(ScriptName AnimName, float Rate, float BlendInTime, float BlendOutTime, bool bLooping, bool bOverride)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10980);
			byte params[32] = { NULL };
			*(ScriptName*)params = AnimName;
			*(float*)&params[8] = Rate;
			*(float*)&params[12] = BlendInTime;
			*(float*)&params[16] = BlendOutTime;
			*(bool*)&params[20] = bLooping;
			*(bool*)&params[24] = bOverride;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[28];
		}
		void PlayCustomAnimByDuration(ScriptName AnimName, float Duration, float BlendInTime, float BlendOutTime, bool bLooping, bool bOverride)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10988);
			byte params[28] = { NULL };
			*(ScriptName*)params = AnimName;
			*(float*)&params[8] = Duration;
			*(float*)&params[12] = BlendInTime;
			*(float*)&params[16] = BlendOutTime;
			*(bool*)&params[20] = bLooping;
			*(bool*)&params[24] = bOverride;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopCustomAnim(float BlendOutTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10995);
			byte params[4] = { NULL };
			*(float*)params = BlendOutTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCustomAnim(ScriptName AnimName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10997);
			byte params[8] = { NULL };
			*(ScriptName*)params = AnimName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActorAnimEndNotification(bool bNewStatus)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11000);
			byte params[4] = { NULL };
			*(bool*)params = bNewStatus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class AnimNodeSequence* GetCustomAnimNodeSeq()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11003);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AnimNodeSequence**)params;
		}
		void SetRootBoneAxisOption(AnimNodeSequence::ERootBoneAxis AxisX, AnimNodeSequence::ERootBoneAxis AxisY, AnimNodeSequence::ERootBoneAxis AxisZ)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11005);
			byte params[3] = { NULL };
			*(AnimNodeSequence::ERootBoneAxis*)params = AxisX;
			*(AnimNodeSequence::ERootBoneAxis*)&params[1] = AxisY;
			*(AnimNodeSequence::ERootBoneAxis*)&params[2] = AxisZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
