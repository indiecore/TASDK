#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKVehicleSimHover." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKVehicleSimHover : public UDKVehicleSimChopper
	{
	public:
		ADD_VAR(::BoolProperty, bUnPoweredDriving, 0x8)
		ADD_VAR(::BoolProperty, bCanClimbSlopes, 0x4)
		ADD_VAR(::BoolProperty, bRepulsorCollisionEnabled, 0x2)
		ADD_VAR(::BoolProperty, bDisableWheelsWhenOff, 0x1)
	};
}
#undef ADD_VAR
