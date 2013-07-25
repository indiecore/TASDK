#pragma once
#include "TribesGame__TrVehicle.h"
#include "Engine__CameraShake.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVehicle_Tank." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrVehicle_Tank." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrVehicle_Tank." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrVehicle_Tank : public TrVehicle
	{
	public:
		ADD_VAR(::FloatProperty, m_CameraShakeEffectiveRadius, 0xFFFFFFFF)
		ADD_OBJECT(CameraShake, m_FireCameraShake)
		ADD_VAR(::ByteProperty, GunnerFiringMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, GunnerFlashCount, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, GunnerWeaponRotation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, GunnerFlashLocation, 0xFFFFFFFF
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'VehicleWeaponFireEffects'
		// Here lies the not-yet-implemented method 'ProcessViewRotationBasedOnSeat'
		// Here lies the not-yet-implemented method 'LimitViewRotation'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
