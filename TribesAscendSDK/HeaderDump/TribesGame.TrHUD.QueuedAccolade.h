#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrHUD.QueuedAccolade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class QueuedAccolade
	{
	public:
		ADD_VAR(::StrProperty, Subtitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Title, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsBadge, 0x1)
		ADD_VAR(::IntProperty, Icon, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
