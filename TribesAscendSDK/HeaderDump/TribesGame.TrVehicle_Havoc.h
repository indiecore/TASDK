#pragma once
#include "TribesGame.TrVehicle_BaseFlying.h"
#include "Core.Object.Rotator.h"
#include "UTGame.UTVehicleWeapon.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVehicle_Havoc." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrVehicle_Havoc : public TrVehicle_BaseFlying
	{
	public:
		ADD_VAR(::FloatProperty, m_fPitchAimAngleRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPitchAimAngle, 0xFFFFFFFF)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_Havoc.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Rotator GetWeaponAim(class UTVehicleWeapon* VWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_Havoc.GetWeaponAim");
			byte* params = (byte*)malloc(16);
			*(class UTVehicleWeapon**)params = VWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
