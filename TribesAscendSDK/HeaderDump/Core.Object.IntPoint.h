#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.IntPoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class IntPoint
	{
	public:
		ADD_VAR(::IntProperty, X, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Y, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
