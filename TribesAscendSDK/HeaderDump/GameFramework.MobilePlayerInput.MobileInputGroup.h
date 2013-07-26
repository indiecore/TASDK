#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MobilePlayerInput.MobileInputGroup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MobileInputGroup
	{
	public:
		ADD_VAR(::StrProperty, GroupName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
