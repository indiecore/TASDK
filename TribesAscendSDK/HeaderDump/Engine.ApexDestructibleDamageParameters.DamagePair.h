#pragma once
#include "Engine.ApexDestructibleDamageParameters.DamageParameters.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ApexDestructibleDamageParameters.DamagePair." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty ApexDestructibleDamageParameters.DamagePair." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DamagePair
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<DamageParameters>, Params, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DamageCauserName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
