#pragma once
#include "Engine__SkelControlSingleBone.h"
#include "TribesGame__TrDevice.h"
#include "Engine__SoundCue.h"
#include "Engine__AnimNodeAdditiveBlending.h"
#include "Engine__AnimNodeSequence.h"
#include "Engine__Projectile.h"
#include "TribesGame__TrProjectile.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_RemoteArxBuster." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_RemoteArxBuster." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_RemoteArxBuster : public TrDevice
	{
	public:
		ADD_OBJECT(SoundCue, m_ArxIdleSound)
		ADD_OBJECT(AnimNodeAdditiveBlending, DetReadyAdditiveAnimNode)
		ADD_VAR(::BoolProperty, r_bIsLeftArmVisible, 0x1)
		ADD_OBJECT(SkelControlSingleBone, DetonatorChild)
		ADD_OBJECT(SkelControlSingleBone, DetonatorControl)
		// Here lies the not-yet-implemented method 'SetArxIdle'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'SetLeftArmVisible'
		// Here lies the not-yet-implemented method 'DetPoseActive'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'AddAmmo'
		// Here lies the not-yet-implemented method 'PerformInactiveReload'
		// Here lies the not-yet-implemented method 'RequestReload'
		// Here lies the not-yet-implemented method 'CanClientRequestReloadNow'
		// Here lies the not-yet-implemented method 'StartFire'
		// Here lies the not-yet-implemented method 'FireAmmunition'
		// Here lies the not-yet-implemented method 'ProjectileFire'
		// Here lies the not-yet-implemented method 'ActivateRemoteRounds'
		// Here lies the not-yet-implemented method 'HideArmTimer'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'OnRemoteProjectileDestroyedByOther'
		// Here lies the not-yet-implemented method 'OnAnimPlay'
		// Here lies the not-yet-implemented method 'OnAnimEnd'
		// Here lies the not-yet-implemented method 'OnPlayRetrieveAnim'
		// Here lies the not-yet-implemented method 'PlayWeaponEquip'
		// Here lies the not-yet-implemented method 'PlayWeaponPutDown'
		// Here lies the not-yet-implemented method 'PutDownFast'
		// Here lies the not-yet-implemented method 'OnSwitchAwayFromWeapon'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
