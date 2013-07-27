#pragma once
#include "Engine.AnimNodeSequence.h"
namespace UnrealScript
{
	class UDKAnimNodeFramePlayer : public AnimNodeSequence
	{
	public:
		void SetAnimation(ScriptName Sequence, float RateScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34585);
			byte params[12] = { NULL };
			*(ScriptName*)params = Sequence;
			*(float*)&params[8] = RateScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAnimPosition(float Perc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34588);
			byte params[4] = { NULL };
			*(float*)params = Perc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
