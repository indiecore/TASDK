#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.Color." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Color
	{
	public:
		ADD_VAR(::ByteProperty, R, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, G, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, B, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, A, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
