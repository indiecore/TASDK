#pragma once
#include "Engine.SequenceEvent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqEvent_AISeeEnemy." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_AISeeEnemy : public SequenceEvent
	{
	public:
		ADD_VAR(::FloatProperty, MaxSightDistance, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
