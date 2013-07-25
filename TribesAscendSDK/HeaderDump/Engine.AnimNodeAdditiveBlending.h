#pragma once
#include "Engine.AnimNodeBlend.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeAdditiveBlending." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodeAdditiveBlending : public AnimNodeBlend
	{
	public:
		ADD_VAR(::BoolProperty, bPassThroughWhenNotRendered, 0x1)
		void SetBlendTarget(float BlendTarget, float BlendTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeAdditiveBlending.SetBlendTarget");
			byte* params = (byte*)malloc(8);
			*(float*)params = BlendTarget;
			*(float*)(params + 4) = BlendTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
