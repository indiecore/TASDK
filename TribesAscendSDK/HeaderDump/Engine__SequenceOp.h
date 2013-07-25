#pragma once
#include "Engine__SequenceObject.h"
#include "Engine__Actor.h"
#include "Engine__SequenceVariable.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
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
		// Here lies the not-yet-implemented method 'GetObjectVars'
		// Here lies the not-yet-implemented method 'HasLinkedOps'
		// Here lies the not-yet-implemented method 'GetLinkedObjects'
		// Here lies the not-yet-implemented method 'GetInterpDataVars'
		// Here lies the not-yet-implemented method 'GetBoolVars'
		// Here lies the not-yet-implemented method 'LinkedVariables'
		// Here lies the not-yet-implemented method 'ActivateOutputLink'
		// Here lies the not-yet-implemented method 'ActivateNamedOutputLink'
		// Here lies the not-yet-implemented method 'Activated'
		// Here lies the not-yet-implemented method 'Deactivated'
		// Here lies the not-yet-implemented method 'VersionUpdated'
		// Here lies the not-yet-implemented method 'PopulateLinkedVariableValues'
		// Here lies the not-yet-implemented method 'PublishLinkedVariableValues'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'GetPawn'
		// Here lies the not-yet-implemented method 'GetController'
		// Here lies the not-yet-implemented method 'ForceActivateInput'
		// Here lies the not-yet-implemented method 'ForceActivateOutput'
	};
}
#undef ADD_VAR
