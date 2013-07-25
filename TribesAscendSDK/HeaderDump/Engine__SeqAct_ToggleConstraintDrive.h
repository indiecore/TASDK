#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_ToggleConstraintDrive." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_ToggleConstraintDrive : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bEnableLinearPositionDrive, 0x4)
		ADD_VAR(::BoolProperty, bEnableLinearvelocityDrive, 0x8)
		ADD_VAR(::BoolProperty, bEnableAngularPositionDrive, 0x1)
		ADD_VAR(::BoolProperty, bEnableAngularVelocityDrive, 0x2)
	};
}
#undef ADD_VAR
