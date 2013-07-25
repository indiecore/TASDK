#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_GiveInventory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_GiveInventory : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bClearExisting, 0x1)
		ADD_VAR(::BoolProperty, bForceReplace, 0x2)
	};
}
#undef ADD_VAR
