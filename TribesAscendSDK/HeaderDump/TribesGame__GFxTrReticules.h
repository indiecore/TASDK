#pragma once
#include "GFxUI__GFxObject.h"
#include "Engine__Weapon.h"
#include "Engine__WorldInfo.h"
#include "TribesGame__GfxTrHud.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrReticules." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GFxTrReticules." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrReticules : public GFxObject
	{
	public:
		ADD_VAR(::IntProperty, m_nCurrentReticuleIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bVisible, 0x1)
		ADD_VAR(::FloatProperty, LastReticuleDepth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHitEnemyTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastAccuracy, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastCrossMode, 0xFFFFFFFF)
		ADD_OBJECT(Weapon, LastWeapon)
		ADD_OBJECT(GFxObject, ActiveReticule)
		ADD_OBJECT(GFxObject, ReticulesMC)
		ADD_OBJECT(WorldInfo, ThisWorld)
		ADD_OBJECT(GfxTrHud, HUD)
		// Here lies the not-yet-implemented method 'CallShowReticule'
		// Here lies the not-yet-implemented method 'CallSetReticuleColor'
		// Here lies the not-yet-implemented method 'ASC_SetCustomReticule'
		// Here lies the not-yet-implemented method 'CallSetReticuleDepth'
		// Here lies the not-yet-implemented method 'ChangeReticule'
		// Here lies the not-yet-implemented method 'SetCustomReticule'
		// Here lies the not-yet-implemented method 'GetCurrentReticuleIndex'
		// Here lies the not-yet-implemented method 'CallSetAccuracy'
		// Here lies the not-yet-implemented method 'CallShowHit'
		// Here lies the not-yet-implemented method 'DisableVehicleAmmoClip'
		// Here lies the not-yet-implemented method 'EnableVehicleAmmoClip'
		// Here lies the not-yet-implemented method 'SetVehicleAmmoClip'
		// Here lies the not-yet-implemented method 'SetPowerupPercentage'
		// Here lies the not-yet-implemented method 'SetLaserPowerupPercentage'
		// Here lies the not-yet-implemented method 'SetVehiclePowerupPercentage'
		// Here lies the not-yet-implemented method 'SetGenericPowerupPercentage'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'SetReticuleVisible'
		// Here lies the not-yet-implemented method 'UpdateReticule'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
