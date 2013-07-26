#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKVehicle.DamageParamScales." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DamageParamScales
	{
	public:
		ADD_VAR(::FloatProperty, Scale, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DamageParamName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
