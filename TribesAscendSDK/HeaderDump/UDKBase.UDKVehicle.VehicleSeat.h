#pragma once
#include "Core.Object.Rotator.h"
#include "Core.Object.Vector.h"
#include "Engine.Pawn.h"
#include "Core.Object.Pointer.h"
#include "Core.Object.Vector2D.h"
#include "Engine.Actor.h"
#include "UDKBase.UDKVehicleMovementEffect.h"
#include "UDKBase.UDKWeapon.h"
#include "Engine.Vehicle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKVehicle.VehicleSeat." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKVehicle.VehicleSeat." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKVehicle.VehicleSeat." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class VehicleSeat
	{
	public:
		ADD_VAR(::BoolProperty, ValidFlagSeat, 0x1)
		ADD_STRUCT(::RotatorProperty, FlagRotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FlagOffset, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, FlagSocketName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTurnInterpSpeed, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vIdealExitLocation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vRidingPassengerMeshOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fViewYawLimit, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bAttachPawnDirectly, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, SeatIconPOS, 0xFFFFFFFF)
		ADD_OBJECT(UDKVehicleMovementEffect, SeatMovementEffect)
		ADD_VAR(::FloatProperty, DriverDamageMult, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, ImpactFlashLightClass)
		ADD_OBJECT(ScriptClass, MuzzleFlashLightClass)
		ADD_VAR(::NameProperty, SeatSocket, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, SeatRotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SeatOffset, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SeatBone, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSeatVisible, 0x1)
		ADD_VAR(::FloatProperty, ViewPitchMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewPitchMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraZoomOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CameraZoomBaseOffset, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, CameraZoomTag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraEyeHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CameraSafeOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CameraBaseOffset, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, CameraTag, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDisableOffsetZAdjust, 0x1)
		ADD_VAR(::FloatProperty, PivotFireOffsetZ, 0xFFFFFFFF)
		ADD_OBJECT(Actor, AimTarget)
		ADD_STRUCT(::VectorProperty, AimPoint, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, LastWeaponRotation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, FiringModeProperty, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, FlashCountProperty, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, FlashLocationProperty, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, WeaponRotationProperty, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, FiringModeName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, FlashCountName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, FlashLocationName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, WeaponRotationName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TurretVarPrefix, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BarrelIndex, 0xFFFFFFFF)
		ADD_OBJECT(UDKWeapon, Gun)
		ADD_OBJECT(ScriptClass, GunClass)
		ADD_OBJECT(Vehicle, SeatPawn)
		ADD_OBJECT(Pawn, StoragePawn)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
