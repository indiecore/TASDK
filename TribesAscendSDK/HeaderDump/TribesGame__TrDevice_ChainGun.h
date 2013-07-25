#pragma once
#include "TribesGame__TrDevice_ConstantFire.h"
#include "Engine__PlayerReplicationInfo.h"
#include "TribesGame__TrSkelControl_SpinControl.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_ChainGun." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_ChainGun." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_ChainGun : public TrDevice_ConstantFire
	{
	public:
		ADD_VAR(::BoolProperty, m_bHasClip, 0x1)
		ADD_VAR(::IntProperty, r_BuffedMaxAmmo, 0xFFFFFFFF)
		ADD_OBJECT(TrSkelControl_SpinControl, m_BarrelSpinControl)
		ADD_VAR(::FloatProperty, m_fCurrSpinTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBuildupTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetBuildUpTime'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'UpdateSoundModulation'
		// Here lies the not-yet-implemented method 'PlayBuildupAnimation'
		// Here lies the not-yet-implemented method 'OnSwitchToWeapon'
		// Here lies the not-yet-implemented method 'PlayWeaponPutDown'
		// Here lies the not-yet-implemented method 'BuffMaxCarriedAmmo'
		// Here lies the not-yet-implemented method 'AddCarriedAmmo'
		// Here lies the not-yet-implemented method 'GetBasePickupAmmoAmount'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
