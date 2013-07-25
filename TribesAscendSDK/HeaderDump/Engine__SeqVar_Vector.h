#pragma once
#include "Engine__SequenceVariable.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqVar_Vector." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqVar_Vector : public SequenceVariable
	{
	public:
		ADD_STRUCT(::VectorProperty, VectValue, 0xFFFFFFFF
	};
}
#undef ADD_STRUCT
