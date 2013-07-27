#pragma once
#include "UDKBase.UDKExplosionLight.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTLinkGunMuzzleFlashLight : public UDKExplosionLight
	{
	public:
		ADD_STRUCT(ScriptArray<UDKExplosionLight::LightValues>, RedTeamTimeShift, 624)
		ADD_STRUCT(ScriptArray<UDKExplosionLight::LightValues>, BlueTeamTimeShift, 636)
		void SetTeam(byte NewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTLinkGunMuzzleFlashLight.SetTeam");
			byte params[1] = { NULL };
			params[0] = NewTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
