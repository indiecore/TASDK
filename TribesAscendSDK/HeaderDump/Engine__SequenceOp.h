#pragma once
#include "Engine__SequenceObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SequenceOp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SequenceOp : public SequenceObject
	{
	public:
		ADD_VAR(::IntProperty, SearchTag, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ActivateCount, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, GamepadID, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPendingOutputConnectorRecalc, 0x100)
		ADD_VAR(::BoolProperty, bPendingInputConnectorRecalc, 0x80)
		ADD_VAR(::BoolProperty, bPendingVarConnectorRecalc, 0x40)
		ADD_VAR(::BoolProperty, bHaveMovingOutputConnector, 0x20)
		ADD_VAR(::BoolProperty, bHaveMovingInputConnector, 0x10)
		ADD_VAR(::BoolProperty, bHaveMovingVarConnector, 0x8)
		ADD_VAR(::BoolProperty, bAutoActivateOutputLinks, 0x4)
		ADD_VAR(::BoolProperty, bLatentExecution, 0x2)
		ADD_VAR(::BoolProperty, bActive, 0x1)
	};
}
#undef ADD_VAR
