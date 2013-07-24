#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PlayerStart." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PlayerStart : public NavigationPoint
	{
	public:
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		ADD_VAR(::BoolProperty, bPrimaryStart, 0x2)
		ADD_VAR(::IntProperty, TeamIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
