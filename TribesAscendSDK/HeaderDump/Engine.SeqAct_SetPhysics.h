#pragma once
#include "Engine.SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_SetPhysics." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_SetPhysics : public SequenceAction
	{
	public:
		ADD_VAR(::ByteProperty, newPhysics, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
