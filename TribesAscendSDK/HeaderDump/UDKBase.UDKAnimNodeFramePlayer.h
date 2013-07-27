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
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = Sequence;
			*(float*)&params[8] = RateScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAnimPosition(float Perc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimNodeFramePlayer.SetAnimPosition");
			byte params[4] = { NULL };
			*(float*)&params[0] = Perc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
