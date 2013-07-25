#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_SetVectorComponents." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqAct_SetVectorComponents." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_SetVectorComponents : public SequenceAction
	{
	public:
		ADD_VAR(::FloatProperty, Z, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Y, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, X, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, OutVector, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
