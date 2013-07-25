#pragma once
#include "Engine__SVehicleWheel.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKVehicleWheel." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKVehicleWheel : public SVehicleWheel
	{
	public:
		ADD_VAR(::FloatProperty, EffectDesiredSpinDir, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDisableWheelOnDeath, 0x2)
		ADD_VAR(::BoolProperty, bUseMaterialSpecificEffects, 0x1)
	};
}
#undef ADD_VAR
