#pragma once
#include "Core.Object.Rotator.h"
#include "Core.Object.Vector.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " CoverLink.CoverSlot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty CoverLink.CoverSlot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty CoverLink.CoverSlot." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CoverSlot
	{
	public:
		ADD_VAR(::BoolProperty, bFailedToFindSurface, 0x200000)
		ADD_VAR(::BoolProperty, bSelected, 0x100000)
		ADD_VAR(::BoolProperty, bPlayerOnly, 0x80000)
		ADD_VAR(::BoolProperty, bForceNoGroundAdjust, 0x40000)
		ADD_VAR(::BoolProperty, bAllowSwatTurn, 0x20000)
		ADD_VAR(::BoolProperty, bAllowClimbUp, 0x10000)
		ADD_VAR(::BoolProperty, bAllowCoverSlip, 0x8000)
		ADD_VAR(::BoolProperty, bAllowMantle, 0x4000)
		ADD_VAR(::BoolProperty, bAllowPopup, 0x2000)
		ADD_VAR(::BoolProperty, bEnabled, 0x1000)
		ADD_VAR(::BoolProperty, bCanSwatTurn_Right, 0x800)
		ADD_VAR(::BoolProperty, bCanSwatTurn_Left, 0x400)
		ADD_VAR(::BoolProperty, bCanCoverSlip_Right, 0x200)
		ADD_VAR(::BoolProperty, bCanCoverSlip_Left, 0x100)
		ADD_VAR(::BoolProperty, bForceCanCoverSlip_Right, 0x80)
		ADD_VAR(::BoolProperty, bForceCanCoverSlip_Left, 0x40)
		ADD_VAR(::BoolProperty, bCanClimbUp, 0x20)
		ADD_VAR(::BoolProperty, bCanMantle, 0x10)
		ADD_VAR(::BoolProperty, bCanPopUp, 0x8)
		ADD_VAR(::BoolProperty, bForceCanPopUp, 0x4)
		ADD_VAR(::BoolProperty, bLeanRight, 0x2)
		ADD_VAR(::BoolProperty, bLeanLeft, 0x1)
		ADD_VAR(::IntProperty, TurnTargetPackedProperties, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, RotationOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LocationOffset, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LocationDescription, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CoverType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ForceCoverType, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SlotValidAfterTime, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, SlotOwner)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
