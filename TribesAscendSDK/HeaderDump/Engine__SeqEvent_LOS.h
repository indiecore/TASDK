#pragma once
#include "Engine__SequenceEvent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqEvent_LOS." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_LOS : public SequenceEvent
	{
	public:
		ADD_VAR(::BoolProperty, bCheckForObstructions, 0x1)
		ADD_VAR(::FloatProperty, TriggerDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ScreenCenterDistance, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetObjClassVersion'
	};
}
#undef ADD_VAR
