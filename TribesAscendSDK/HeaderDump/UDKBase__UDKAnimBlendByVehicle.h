#pragma once
#include "Engine__Vehicle.h"
#include "UDKBase__UDKAnimBlendBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimBlendByVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKAnimBlendByVehicle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKAnimBlendByVehicle : public UDKAnimBlendBase
	{
	public:
		ADD_OBJECT(Vehicle, LastVehicle)
		ADD_VAR(::BoolProperty, bLastPawnDriving, 0x1)
		void UpdateVehicleState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimBlendByVehicle.UpdateVehicleState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
