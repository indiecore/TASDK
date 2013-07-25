#pragma once
#include "Engine.SequenceEvent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqEvent_AnimNotify." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_AnimNotify : public SequenceEvent
	{
	public:
		ADD_VAR(::NameProperty, NotifyName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
