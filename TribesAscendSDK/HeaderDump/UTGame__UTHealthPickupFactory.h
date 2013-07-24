#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTHealthPickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTHealthPickupFactory : public UTItemPickupFactory
	{
	public:
		ADD_VAR(::BoolProperty, bSuperHeal, 0x1)
		ADD_VAR(::IntProperty, HealingAmount, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
