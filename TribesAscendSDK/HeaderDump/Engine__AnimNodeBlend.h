#pragma once
#include "Engine__AnimNodeBlendBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeBlend." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodeBlend : public AnimNodeBlendBase
	{
	public:
		ADD_VAR(::BoolProperty, bSkipBlendWhenNotRendered, 0x1)
		ADD_VAR(::FloatProperty, BlendTimeToGo, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Child2WeightTarget, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Child2Weight, 0xFFFFFFFF)
		void SetBlendTarget(float BlendTarget, float BlendTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeBlend.SetBlendTarget");
			byte* params = (byte*)malloc(8);
			*(float*)params = BlendTarget;
			*(float*)(params + 4) = BlendTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
