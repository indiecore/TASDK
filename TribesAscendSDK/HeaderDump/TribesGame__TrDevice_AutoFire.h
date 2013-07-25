#pragma once
#include "TribesGame__TrDevice.h"
#include "Engine__Projectile.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_AutoFire." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_AutoFire." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_AutoFire : public TrDevice
	{
	public:
		ADD_VAR(::BoolProperty, m_bPullPinFire, 0x1)
		ADD_VAR(::FloatProperty, m_fPullPinTime, 0xFFFFFFFF)
		ADD_OBJECT(TrDevice, m_PostFireDevice)
		ADD_VAR(::FloatProperty, m_fBuildupTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetBuildUpTime'
		// Here lies the not-yet-implemented method 'GetEquipTime'
		// Here lies the not-yet-implemented method 'GetPutDownTime'
		// Here lies the not-yet-implemented method 'PlayFireAnimation'
		// Here lies the not-yet-implemented method 'FireAmmunition'
		// Here lies the not-yet-implemented method 'AddCarriedAmmo'
		// Here lies the not-yet-implemented method 'PerformInactiveReload'
		// Here lies the not-yet-implemented method 'HasAmmo'
		// Here lies the not-yet-implemented method 'StartFire'
		// Here lies the not-yet-implemented method 'SetPostFireDevice'
		// Here lies the not-yet-implemented method 'SwitchToPostFireDevice'
		// Here lies the not-yet-implemented method 'OnAnimEnd'
		// Here lies the not-yet-implemented method 'CanFireNow'
		// Here lies the not-yet-implemented method 'DoOverrideNextWeapon'
		// Here lies the not-yet-implemented method 'DoOverridePrevWeapon'
		// Here lies the not-yet-implemented method 'CanAutoDeviceFireNow'
		// Here lies the not-yet-implemented method 'RequestReload'
		// Here lies the not-yet-implemented method 'OnClientReloaded'
		// Here lies the not-yet-implemented method 'ClientFinishedReload'
		// Here lies the not-yet-implemented method 'OnReloadComplete'
		// Here lies the not-yet-implemented method 'IncrementFlashCount'
		// Here lies the not-yet-implemented method 'CanViewZoom'
		// Here lies the not-yet-implemented method 'ConsumeAmmo'
		// Here lies the not-yet-implemented method 'ConsumeAmmo_Internal'
		// Here lies the not-yet-implemented method 'ProjectileFire'
		// Here lies the not-yet-implemented method 'OnSwitchAwayFromWeapon'
		// Here lies the not-yet-implemented method 'HolderEnteredVehicle'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
