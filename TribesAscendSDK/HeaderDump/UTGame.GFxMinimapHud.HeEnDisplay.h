#pragma once
#include "GFxUI.GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxMinimapHud.HeEnDisplay." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GFxMinimapHud.HeEnDisplay." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class HeEnDisplay
	{
	public:
		ADD_OBJECT(GFxObject, EnergyBarMC)
		ADD_OBJECT(GFxObject, EnergyTF)
		ADD_VAR(::BoolProperty, HealthNormOn, 0x1)
		ADD_OBJECT(GFxObject, HealthCritMC)
		ADD_OBJECT(GFxObject, HealthNormMC)
		ADD_OBJECT(GFxObject, HealthBarMC)
		ADD_OBJECT(GFxObject, HealthTF)
		ADD_VAR(::FloatProperty, LastEnergy, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHealth, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
