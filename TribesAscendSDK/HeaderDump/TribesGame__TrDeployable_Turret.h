#pragma once
#include "Engine__SoundCue.h"
#include "TribesGame__TrDeployable.h"
#include "Engine__Pawn.h"
#include "Engine__Weapon.h"
#include "Engine__Texture2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployable_Turret." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeployable_Turret." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployable_Turret : public TrDeployable
	{
	public:
		ADD_VAR(::FloatProperty, m_fLastStallTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFireStallRestoreTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeToIgnoreInvulnerable, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeToAcquireTarget, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTargetAcquiredTime, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, m_TargetAcquiredSoundCue)
		ADD_VAR(::FloatProperty, m_fDeltaFireInterval, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, m_MuzzleFlashLightClass)
		ADD_VAR(::BoolProperty, m_bCanTargetVehicles, 0x2)
		ADD_VAR(::BoolProperty, m_bEnabled, 0x1)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'DeployComplete'
		// Here lies the not-yet-implemented method 'AcquireTarget'
		// Here lies the not-yet-implemented method 'GetAcquireDelayTime'
		// Here lies the not-yet-implemented method 'CleanupIgnoreList'
		// Here lies the not-yet-implemented method 'CanTargetPawn'
		// Here lies the not-yet-implemented method 'GetTargetPawn'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'UpdateAim'
		// Here lies the not-yet-implemented method 'PlayFireEffects'
		// Here lies the not-yet-implemented method 'CauseMuzzleFlash'
		// Here lies the not-yet-implemented method 'MuzzleFlashTimer'
		// Here lies the not-yet-implemented method 'SetMuzzleFlashParams'
		// Here lies the not-yet-implemented method 'GetWeaponStartTraceLocation'
		// Here lies the not-yet-implemented method 'GetMarker'
		// Here lies the not-yet-implemented method 'AwardKillAssists'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
