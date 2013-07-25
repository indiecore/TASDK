#pragma once
#include "Engine.SequenceEvent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqEvent_MobileRawInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileRawInput : public SequenceEvent
	{
	public:
		ADD_VAR(::FloatProperty, TimeStamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TouchLocationY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TouchLocationX, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TouchIndex, 0xFFFFFFFF)
		void RegisterEvent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqEvent_MobileRawInput.RegisterEvent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
