#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKVehicleSimChopper.AnglePID." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnglePID
	{
	public:
		ADD_VAR(::FloatProperty, PrevError, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PrevIntegral, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IGain, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DGain, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PGain, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
