#pragma once
#include "Engine__Inventory.h"
#include "Engine__Actor.h"
#include "Engine__AIController.h"
#include "Engine__HUD.h"
#include "Engine__Projectile.h"
#include "Engine__AnimNodeSequence.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Weapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Weapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Weapon." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Weapon : public Inventory
	{
	public:
		ADD_VAR(::BoolProperty, bInstantHit, 0x10)
		ADD_VAR(::FloatProperty, WeaponRange, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CurrentFireMode, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CachedMaxRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AIRating, 0xFFFFFFFF)
		ADD_OBJECT(AIController, AIController)
		ADD_VAR(::FloatProperty, Priority, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DefaultAnimSpeed, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bMeleeWeapon, 0x20)
		ADD_VAR(::BoolProperty, bWasDoNotActivate, 0x8)
		ADD_VAR(::BoolProperty, bWasOptionalSet, 0x4)
		ADD_VAR(::BoolProperty, bCanThrow, 0x2)
		ADD_VAR(::BoolProperty, bWeaponPutDown, 0x1)
		ADD_STRUCT(::VectorProperty, FireOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, PutDownTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EquipTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetTraceRange'
		// Here lies the not-yet-implemented method 'HasAnyAmmo'
		// Here lies the not-yet-implemented method 'GetAIRating'
		// Here lies the not-yet-implemented method 'GetWeaponRating'
		// Here lies the not-yet-implemented method 'TryPutDown'
		// Here lies the not-yet-implemented method 'DenyClientWeaponSet'
		// Here lies the not-yet-implemented method 'CanAttack'
		// Here lies the not-yet-implemented method 'FireOnRelease'
		// Here lies the not-yet-implemented method 'IsFiring'
		// Here lies the not-yet-implemented method 'CanThrow'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'ItemRemovedFromInvManager'
		// Here lies the not-yet-implemented method 'HolderDied'
		// Here lies the not-yet-implemented method 'DoOverrideNextWeapon'
		// Here lies the not-yet-implemented method 'DoOverridePrevWeapon'
		// Here lies the not-yet-implemented method 'DropFrom'
		// Here lies the not-yet-implemented method 'ClientWeaponThrown'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'GetWeaponDebug'
		// Here lies the not-yet-implemented method 'GetPendingFireLength'
		// Here lies the not-yet-implemented method 'PendingFire'
		// Here lies the not-yet-implemented method 'ConsumeAmmo'
		// Here lies the not-yet-implemented method 'AddAmmo'
		// Here lies the not-yet-implemented method 'HasAmmo'
		// Here lies the not-yet-implemented method 'SetPendingFire'
		// Here lies the not-yet-implemented method 'ClearPendingFire'
		// Here lies the not-yet-implemented method 'GetProjectileClass'
		// Here lies the not-yet-implemented method 'AddSpread'
		// Here lies the not-yet-implemented method 'MaxRange'
		// Here lies the not-yet-implemented method 'GetWeaponAnimNodeSeq'
		// Here lies the not-yet-implemented method 'PlayWeaponAnimation'
		// Here lies the not-yet-implemented method 'StopWeaponAnimation'
		// Here lies the not-yet-implemented method 'PlayFireEffects'
		// Here lies the not-yet-implemented method 'StopFireEffects'
		// Here lies the not-yet-implemented method 'GetFireInterval'
		// Here lies the not-yet-implemented method 'TimeWeaponFiring'
		// Here lies the not-yet-implemented method 'RefireCheckTimer'
		// Here lies the not-yet-implemented method 'TimeWeaponPutDown'
		// Here lies the not-yet-implemented method 'TimeWeaponEquipping'
		// Here lies the not-yet-implemented method 'Activate'
		// Here lies the not-yet-implemented method 'PutDownWeapon'
		// Here lies the not-yet-implemented method 'DenyPickupQuery'
		// Here lies the not-yet-implemented method 'WeaponEmpty'
		// Here lies the not-yet-implemented method 'IncrementFlashCount'
		// Here lies the not-yet-implemented method 'ClearFlashCount'
		// Here lies the not-yet-implemented method 'SetFlashLocation'
		// Here lies the not-yet-implemented method 'ClearFlashLocation'
		// Here lies the not-yet-implemented method 'AttachWeaponTo'
		// Here lies the not-yet-implemented method 'DetachWeapon'
		// Here lies the not-yet-implemented method 'ClientGivenTo'
		// Here lies the not-yet-implemented method 'ClientWeaponSet'
		// Here lies the not-yet-implemented method 'StartFire'
		// Here lies the not-yet-implemented method 'ServerStartFire'
		// Here lies the not-yet-implemented method 'BeginFire'
		// Here lies the not-yet-implemented method 'StopFire'
		// Here lies the not-yet-implemented method 'ServerStopFire'
		// Here lies the not-yet-implemented method 'EndFire'
		// Here lies the not-yet-implemented method 'ForceEndFire'
		// Here lies the not-yet-implemented method 'SendToFiringState'
		// Here lies the not-yet-implemented method 'SetCurrentFireMode'
		// Here lies the not-yet-implemented method 'FireModeUpdated'
		// Here lies the not-yet-implemented method 'FireAmmunition'
		// Here lies the not-yet-implemented method 'GetAdjustedAim'
		// Here lies the not-yet-implemented method 'GetTraceOwner'
		// Here lies the not-yet-implemented method 'CalcWeaponFire'
		// Here lies the not-yet-implemented method 'PassThroughDamage'
		// Here lies the not-yet-implemented method 'InstantFire'
		// Here lies the not-yet-implemented method 'ProcessInstantHit'
		// Here lies the not-yet-implemented method 'ProjectileFire'
		// Here lies the not-yet-implemented method 'CustomFire'
		// Here lies the not-yet-implemented method 'GetMuzzleLoc'
		// Here lies the not-yet-implemented method 'GetPhysicalFireStartLoc'
		// Here lies the not-yet-implemented method 'HandleFinishedFiring'
		// Here lies the not-yet-implemented method 'NotifyWeaponFired'
		// Here lies the not-yet-implemented method 'NotifyWeaponFinishedFiring'
		// Here lies the not-yet-implemented method 'ShouldRefire'
		// Here lies the not-yet-implemented method 'StillFiring'
		// Here lies the not-yet-implemented method 'WeaponIsDown'
		// Here lies the not-yet-implemented method 'CacheAIController'
		// Here lies the not-yet-implemented method 'GetTargetDistance'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
