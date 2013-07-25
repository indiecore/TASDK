#pragma once
#include "Engine__SeqAct_SetSequenceVariable.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqAct_SetVector." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_SetVector : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_STRUCT(::VectorProperty, DefaultValue, 0xFFFFFFFF
	};
}
#undef ADD_STRUCT
