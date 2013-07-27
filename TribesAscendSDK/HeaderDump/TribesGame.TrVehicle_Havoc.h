#pragma once
#include "TribesGame.TrVehicle_BaseFlying.h"
#include "Core.Object.h"
#include "UTGame.UTVehicleWeapon.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrVehicle_Havoc : public TrVehicle_BaseFlying
	{
	public:
		ADD_STRUCT(float, m_fPitchAimAngleRotation, 3296)
		ADD_STRUCT(float, m_fPitchAimAngle, 3292)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_Havoc.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Object::Rotator GetWeaponAim(class UTVehicleWeapon* VWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_Havoc.GetWeaponAim");
			byte params[16] = { NULL };
			*(class UTVehicleWeapon**)&params[0] = VWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[4];
		}
	};
}
#undef ADD_STRUCT
