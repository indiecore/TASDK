#pragma once
#include "Engine.PostProcessEffect.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class PostProcessChain : public Object
	{
	public:
		class PostProcessEffect* FindPostProcessEffect(ScriptName EffectName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PostProcessChain.FindPostProcessEffect");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = EffectName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PostProcessEffect**)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
