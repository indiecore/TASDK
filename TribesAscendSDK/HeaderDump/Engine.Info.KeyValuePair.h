#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Info.KeyValuePair." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class KeyValuePair
	{
	public:
		ADD_VAR(::StrProperty, Value, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Key, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
