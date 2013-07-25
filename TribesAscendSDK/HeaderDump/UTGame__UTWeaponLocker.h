#pragma once
#include "UTGame__UTBot.h"
#include "UTGame__UTPickupFactory.h"
#include "Engine__ParticleSystem.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTWeaponLocker." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTWeaponLocker." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTWeaponLocker." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTWeaponLocker : public UTPickupFactory
	{
	public:
		ADD_VAR(::FloatProperty, NextProximityCheckTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ScaleRate, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, WeaponSpawnEffectTemplate)
		ADD_OBJECT(ParticleSystem, ActiveEffectTemplate)
		ADD_OBJECT(ParticleSystem, InactiveEffectTemplate)
		ADD_VAR(::FloatProperty, ProximityDistanceSquared, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentWeaponScaleX, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bScalingUp, 0x4)
		ADD_VAR(::BoolProperty, bPlayerNearby, 0x2)
		ADD_VAR(::BoolProperty, bIsActive, 0x1)
		ADD_VAR(::StrProperty, LockerString, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UTGame.UTWeaponLocker.ReplacementWeaponEntry' for the property named 'ReplacementWeapons'!
		// Here lies the not-yet-implemented method 'BotDesireability'
		// Here lies the not-yet-implemented method 'SetInitialState'
		// Here lies the not-yet-implemented method 'ShouldCamp'
		// Here lies the not-yet-implemented method 'AddCustomer'
		// Here lies the not-yet-implemented method 'HasCustomer'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'InitializeWeapons'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'ReplaceWeapon'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'GetHumanReadableName'
		// Here lies the not-yet-implemented method 'DetourWeight'
		// Here lies the not-yet-implemented method 'InitializePickup'
		// Here lies the not-yet-implemented method 'ShowActive'
		// Here lies the not-yet-implemented method 'NotifyLocalPlayerDead'
		// Here lies the not-yet-implemented method 'SetPlayerNearby'
		// Here lies the not-yet-implemented method 'DestroyWeapons'
		// Here lies the not-yet-implemented method 'ShowHidden'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
