#pragma once
#include "Engine.SeqVar_Int.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqVar_RandomInt." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqVar_RandomInt : public SeqVar_Int
	{
	public:
		ADD_VAR(::IntProperty, Max, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Min, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
