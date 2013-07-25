#pragma once
#include "Engine__SequenceAction.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_Teleport." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_Teleport : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bCheckOverlap, 0x2)
		ADD_VAR(::BoolProperty, bUpdateRotation, 0x1)
		ADD_VAR(::FloatProperty, TeleportDistance, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'ShouldTeleport'
		// Here lies the not-yet-implemented method 'GetObjClassVersion'
	};
}
#undef ADD_VAR
