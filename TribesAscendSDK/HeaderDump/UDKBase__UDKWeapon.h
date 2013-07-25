#pragma once
#include "Engine__Weapon.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKWeapon : public Weapon
	{
	public:
		ADD_VAR(::FloatProperty, AimTraceRange, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, HitEnemy, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AmmoCount, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bConsiderProjectileAcceleration, 0x2)
		ADD_VAR(::BoolProperty, bLeadTarget, 0x1)
	};
}
#undef ADD_VAR
