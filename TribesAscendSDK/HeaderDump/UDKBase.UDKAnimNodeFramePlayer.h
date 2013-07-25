#pragma once
#include "Engine.AnimNodeSequence.h"
namespace UnrealScript
{
	class UDKAnimNodeFramePlayer : public AnimNodeSequence
	{
	public:
		void SetAnimation(ScriptName Sequence, float RateScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimNodeFramePlayer.SetAnimation");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = Sequence;
			*(float*)(params + 8) = RateScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAnimPosition(float Perc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimNodeFramePlayer.SetAnimPosition");
			byte* params = (byte*)malloc(4);
			*(float*)params = Perc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
