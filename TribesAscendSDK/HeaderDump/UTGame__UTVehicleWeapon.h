#pragma once
#include "UTGame__UTWeapon.h"
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
		ADD_VAR(::BoolProperty, bDebugTurret, 0x10)
		ADD_VAR(::BoolProperty, bCurrentlyZoomed, 0x2)
		ADD_VAR(::BoolProperty, bPlaySoundFromSocket, 0x1)
		ADD_VAR(::FloatProperty, MaxFinalAimAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentCrosshairScaling, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastInCorrectAimTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastCorrectAimTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect' for the property named 'DefaultAltImpactEffect'!
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect' for the property named 'DefaultImpactEffect'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
