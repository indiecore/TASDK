#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameTypes.ShakeParams." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ShakeParams
	{
	public:
		ADD_VAR(::ByteProperty, X, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Y, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Z, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Padding, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
