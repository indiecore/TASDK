#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " InternetLink.IpAddr." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class IpAddr
	{
	public:
		ADD_VAR(::IntProperty, Port, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Addr, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
