#pragma once
#include "Engine.SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_ToggleInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_ToggleInput : public SeqAct_Toggle
	{
	public:
		ADD_VAR(::BoolProperty, bToggleMovement, 0x1)
		ADD_VAR(::BoolProperty, bToggleTurning, 0x2)
	};
}
#undef ADD_VAR
