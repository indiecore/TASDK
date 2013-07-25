#pragma once
#include "Engine__AnimNodeBlend.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodePlayCustomAnim." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodePlayCustomAnim : public AnimNodeBlend
	{
	public:
		ADD_VAR(::FloatProperty, CustomPendingBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsPlayingCustomAnim, 0x1)
		float PlayCustomAnim(ScriptName AnimName, float Rate, float BlendInTime, float BlendOutTime, bool bLooping, bool bOverride)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodePlayCustomAnim.PlayCustomAnim");
			byte* params = (byte*)malloc(32);
			*(ScriptName*)params = AnimName;
			*(float*)(params + 8) = Rate;
			*(float*)(params + 12) = BlendInTime;
			*(float*)(params + 16) = BlendOutTime;
			*(bool*)(params + 20) = bLooping;
			*(bool*)(params + 24) = bOverride;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 28);
			free(params);
			return returnVal;
		}
		void PlayCustomAnimByDuration(ScriptName AnimName, float Duration, float BlendInTime, float BlendOutTime, bool bLooping, bool bOverride)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodePlayCustomAnim.PlayCustomAnimByDuration");
			byte* params = (byte*)malloc(28);
			*(ScriptName*)params = AnimName;
			*(float*)(params + 8) = Duration;
			*(float*)(params + 12) = BlendInTime;
			*(float*)(params + 16) = BlendOutTime;
			*(bool*)(params + 20) = bLooping;
			*(bool*)(params + 24) = bOverride;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopCustomAnim(float BlendOutTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodePlayCustomAnim.StopCustomAnim");
			byte* params = (byte*)malloc(4);
			*(float*)params = BlendOutTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCustomAnim(ScriptName AnimName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodePlayCustomAnim.SetCustomAnim");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = AnimName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetActorAnimEndNotification(bool bNewStatus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodePlayCustomAnim.SetActorAnimEndNotification");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewStatus;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class AnimNodeSequence* GetCustomAnimNodeSeq()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodePlayCustomAnim.GetCustomAnimNodeSeq");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class AnimNodeSequence**)params;
			free(params);
			return returnVal;
		}
		void SetRootBoneAxisOption(byte AxisX, byte AxisY, byte AxisZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodePlayCustomAnim.SetRootBoneAxisOption");
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
