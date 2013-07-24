#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKWeaponShield." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKWeaponShield : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bIgnoreFlaggedProjectiles, 0x1)
	};
}
#undef ADD_VAR
