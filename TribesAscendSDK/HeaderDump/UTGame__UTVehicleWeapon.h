#pragma once
#include "UTGame__UTPlayerController.h"
#include "Engine__Actor.h"
#include "UTGame__UTWeapon.h"
#include "Engine__HUD.h"
#include "UTGame__UTVehicle.h"
#include "Engine__SoundCue.h"
#include "Engine__PhysicalMaterial.h"
#include "Engine__Canvas.h"
#include "Engine__Projectile.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTVehicleWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTVehicleWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTVehicleWeapon." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTVehicleWeapon : public UTWeapon
	{
	public:
		ADD_VAR(::IntProperty, SeatIndex, 0xFFFFFFFF)
		ADD_OBJECT(UTVehicle, MyVehicle)
		ADD_VAR(::BoolProperty, bIgnoreSocketPitchRotation, 0x4)
		ADD_VAR(::BoolProperty, bIgnoreDownwardPitch, 0x8)
		ADD_OBJECT(SoundCue, BulletWhip)
		ADD_OBJECT(ScriptClass, VehicleClass)
		ADD_VAR(::BoolProperty, bDebugTurret, 0x10)
		ADD_VAR(::BoolProperty, bCurrentlyZoomed, 0x2)
		ADD_VAR(::BoolProperty, bPlaySoundFromSocket, 0x1)
		ADD_VAR(::FloatProperty, MaxFinalAimAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentCrosshairScaling, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastInCorrectAimTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastCorrectAimTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect' for the property named 'DefaultAltImpactEffect'!
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect' for the property named 'DefaultImpactEffect'!
		// Here lies the not-yet-implemented method 'GetMaxFinalAimAdjustment'
		// Here lies the not-yet-implemented method 'GetAdjustedAim'
		// Here lies the not-yet-implemented method 'GetFireTriggerTag'
		// Here lies the not-yet-implemented method 'GetImpactEffect'
		// Here lies the not-yet-implemented method 'CanHitDesiredTarget'
		// Here lies the not-yet-implemented method 'DrawKillIcon'
		// Here lies the not-yet-implemented method 'GetCrosshairScaling'
		// Here lies the not-yet-implemented method 'DrawWeaponCrosshair'
		// Here lies the not-yet-implemented method 'GetDesiredAimPoint'
		// Here lies the not-yet-implemented method 'GetFireStartLocationAndRotation'
		// Here lies the not-yet-implemented method 'IsAimCorrect'
		// Here lies the not-yet-implemented method 'GetFireInterval'
		// Here lies the not-yet-implemented method 'AttachWeaponTo'
		// Here lies the not-yet-implemented method 'DetachWeapon'
		// Here lies the not-yet-implemented method 'Activate'
		// Here lies the not-yet-implemented method 'PutDownWeapon'
		// Here lies the not-yet-implemented method 'GetPhysicalFireStartLoc'
		// Here lies the not-yet-implemented method 'BeginFire'
		// Here lies the not-yet-implemented method 'EndFire'
		// Here lies the not-yet-implemented method 'ProjectileFire'
		// Here lies the not-yet-implemented method 'InstantFireStartTrace'
		// Here lies the not-yet-implemented method 'InstantFireEndTrace'
		// Here lies the not-yet-implemented method 'GetTraceOwner'
		// Here lies the not-yet-implemented method 'NotifyVehicleDeployed'
		// Here lies the not-yet-implemented method 'NotifyVehicleUndeployed'
		// Here lies the not-yet-implemented method 'WeaponPlaySound'
		// Here lies the not-yet-implemented method 'GetZoomedState'
		// Here lies the not-yet-implemented method 'ServerSetZoom'
		// Here lies the not-yet-implemented method 'StartZoom'
		// Here lies the not-yet-implemented method 'EndZoom'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
