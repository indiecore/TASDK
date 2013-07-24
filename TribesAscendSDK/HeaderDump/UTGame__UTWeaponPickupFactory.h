#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTWeaponPickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTWeaponPickupFactory : public UTPickupFactory
	{
	public:
		ADD_VAR(::FloatProperty, WeaponPickupScaling, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsActive, 0x2)
		ADD_VAR(::BoolProperty, bWeaponStay, 0x1)
	};
}
#undef ADD_VAR
