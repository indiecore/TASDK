#pragma once
#include "Engine__SequenceEvent.h"
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
	};
}
#undef ADD_VAR
