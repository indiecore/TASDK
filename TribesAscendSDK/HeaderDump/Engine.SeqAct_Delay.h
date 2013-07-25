#pragma once
#include "Engine.SeqAct_Latent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_Delay." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_Delay : public SeqAct_Latent
	{
	public:
		ADD_VAR(::FloatProperty, RemainingTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Duration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DefaultDuration, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bStartWillRestart, 0x2)
		ADD_VAR(::BoolProperty, bDelayActive, 0x1)
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_Delay.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetDelayActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_Delay.ResetDelayActive");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
