#pragma once
#include "Engine__K2Input.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.K2Input_Float." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class K2Input_Float : public K2Input
	{
	public:
		ADD_VAR(::FloatProperty, DefaultFloat, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
