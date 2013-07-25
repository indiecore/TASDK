#pragma once
#include "Engine__MaterialInstanceConstant.h"
#include "TribesGame__TrVehicleWeapon_BurstShot.h"
#include "TribesGame__TrEffect_MovableDecal.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrVehicleWeapon_HavocPilot." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrVehicleWeapon_HavocPilot : public TrVehicleWeapon_BurstShot
	{
	public:
		ADD_OBJECT(TrEffect_MovableDecal, m_BombMarkerDecal)
		ADD_OBJECT(MaterialInstanceConstant, m_BombMarkerMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_BombMarkerTemplate)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon_HavocPilot.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon_HavocPilot.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon_HavocPilot.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
