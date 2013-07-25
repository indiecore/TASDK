#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_SetParticleSysParam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_SetParticleSysParam : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bOverrideScalar, 0x1)
		ADD_VAR(::FloatProperty, ScalarValue, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
