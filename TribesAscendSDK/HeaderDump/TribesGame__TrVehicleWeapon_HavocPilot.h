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
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'Tick'
	};
}
#undef ADD_OBJECT
