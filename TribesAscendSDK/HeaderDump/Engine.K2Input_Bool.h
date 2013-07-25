#pragma once
#include "Engine.K2Input.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.K2Input_Bool." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class K2Input_Bool : public K2Input
	{
	public:
		ADD_VAR(::BoolProperty, bDefaultBool, 0x1)
	};
}
#undef ADD_VAR
