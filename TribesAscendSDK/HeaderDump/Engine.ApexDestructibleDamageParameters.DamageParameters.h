#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ApexDestructibleDamageParameters.DamageParameters." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DamageParameters
	{
	public:
		ADD_VAR(::FloatProperty, Momentum, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Radius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BaseDamage, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, OverrideMode, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
