#pragma once
#include "TribesGame__TrSkelControl_SpinControl.h"
#include "TribesGame__TrVehicleWeapon_FullAuto.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrVehicleWeapon_BeowulfGunner." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrVehicleWeapon_BeowulfGunner : public TrVehicleWeapon_FullAuto
	{
	public:
		ADD_OBJECT(TrSkelControl_SpinControl, m_BarrelSpinControl)
		void InitVehicleGun()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon_BeowulfGunner.InitVehicleGun");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Activate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon_BeowulfGunner.Activate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
