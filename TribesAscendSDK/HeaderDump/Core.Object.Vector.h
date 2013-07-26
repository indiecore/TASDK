#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.Vector." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Vector
	{
	public:
		ADD_VAR(::FloatProperty, X, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Y, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Z, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
