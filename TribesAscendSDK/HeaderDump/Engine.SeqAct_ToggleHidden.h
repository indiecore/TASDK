#pragma once
#include "Engine.SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_ToggleHidden." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_ToggleHidden : public SeqAct_Toggle
	{
	public:
		ADD_VAR(::BoolProperty, bToggleBasedActors, 0x1)
	};
}
#undef ADD_VAR
