#pragma once
#include "Engine.AnimNode.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeBlendBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodeBlendBase : public AnimNode
	{
	public:
		ADD_VAR(::ByteProperty, BlendType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFixNumChildren, 0x1)
		void PlayAnim(bool bLoop, float Rate, float StartTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeBlendBase.PlayAnim");
			byte* params = (byte*)malloc(12);
			*(bool*)params = bLoop;
			*(float*)(params + 4) = Rate;
			*(float*)(params + 8) = StartTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeBlendBase.StopAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplayAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeBlendBase.ReplayAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
