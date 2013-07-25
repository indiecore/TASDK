#pragma once
#include "Engine.SequenceEvent.h"
#include "Engine.Texture2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqEvent_Used." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqEvent_Used." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqEvent_Used : public SequenceEvent
	{
	public:
		ADD_VAR(::BoolProperty, bAimToInteract, 0x1)
		ADD_VAR(::FloatProperty, InteractDistance, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, InteractIcon)
		ADD_VAR(::StrProperty, InteractText, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
