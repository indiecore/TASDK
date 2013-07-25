#pragma once
#include "Engine__AnimNodeBlend.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeCrossfader." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodeCrossfader : public AnimNodeBlend
	{
	public:
		ADD_VAR(::FloatProperty, PendingBlendOutTimeOneShot, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDontBlendOutOneShot, 0x1)
		ADD_VAR(::NameProperty, DefaultAnimSeqName, 0xFFFFFFFF)
		void PlayOneShotAnim(ScriptName AnimSeqName, float BlendInTime, float BlendOutTime, bool bDontBlendOut, float Rate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeCrossfader.PlayOneShotAnim");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = AnimSeqName;
			*(float*)(params + 8) = BlendInTime;
			*(float*)(params + 12) = BlendOutTime;
			*(bool*)(params + 16) = bDontBlendOut;
			*(float*)(params + 20) = Rate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BlendToLoopingAnim(ScriptName AnimSeqName, float BlendInTime, float Rate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeCrossfader.BlendToLoopingAnim");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = AnimSeqName;
			*(float*)(params + 8) = BlendInTime;
			*(float*)(params + 12) = Rate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptName GetAnimName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeCrossfader.GetAnimName");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
		class AnimNodeSequence* GetActiveChild()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeCrossfader.GetActiveChild");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class AnimNodeSequence**)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
