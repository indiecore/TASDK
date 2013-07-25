#pragma once
#include "Engine__Pawn.h"
#include "Engine__NavigationPoint.h"
#include "Engine__SeqAct_ModifyCover.h"
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Scout.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CoverLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.CoverLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.CoverLink." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CoverLink : public NavigationPoint
	{
	public:
		ADD_VAR(::BoolProperty, bClaimAllSlots, 0x4)
		ADD_VAR(::BoolProperty, bCircular, 0x20)
		ADD_VAR(::BoolProperty, bDisabled, 0x2)
		ADD_VAR(::BoolProperty, bFractureOnTouch, 0x200)
		ADD_VAR(::BoolProperty, GLOBAL_bUseSlotMarkers, 0x1)
		ADD_VAR(::BoolProperty, bAutoSort, 0x8)
		ADD_VAR(::BoolProperty, bAutoAdjust, 0x10)
		ADD_VAR(::BoolProperty, bLooped, 0x40)
		ADD_VAR(::BoolProperty, bPlayerOnly, 0x80)
		ADD_VAR(::BoolProperty, bDynamicCover, 0x100)
		ADD_VAR(::BoolProperty, bDebug_FireLinks, 0x400)
		ADD_VAR(::BoolProperty, bDebug_ExposedLinks, 0x800)
		ADD_VAR(::BoolProperty, bDebug_CoverGen, 0x1000)
		ADD_VAR(::BoolProperty, bDoAutoSlotDensityFixup, 0x2000)
		ADD_VAR(::FloatProperty, LeanTraceDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InvalidateDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxFireLinkDist, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CircularOrigin, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, CircularRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AlignDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AutoCoverSlotInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StandHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MidHeight, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StandingLeanOffset, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, CrouchLeanOffset, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, PopupOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, SlipDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TurnDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DangerScale, 0xFFFFFFFF)
		ADD_OBJECT(CoverLink, NextCoverLink)
		ADD_VAR(::ByteProperty, LocationDescription, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetFireLinkTargetCoverInfo'
		// Here lies the not-yet-implemented method 'PackFireLinkInteractionInfo'
		// Here lies the not-yet-implemented method 'UnPackFireLinkInteractionInfo'
		// Here lies the not-yet-implemented method 'GetSlotLocation'
		// Here lies the not-yet-implemented method 'GetSlotRotation'
		// Here lies the not-yet-implemented method 'GetSlotViewPoint'
		// Here lies the not-yet-implemented method 'IsExposedTo'
		// Here lies the not-yet-implemented method 'SetInvalidUntil'
		// Here lies the not-yet-implemented method 'Claim'
		// Here lies the not-yet-implemented method 'UnClaim'
		// Here lies the not-yet-implemented method 'IsValidClaim'
		// Here lies the not-yet-implemented method 'IsValidClaimBetween'
		// Here lies the not-yet-implemented method 'IsStationarySlot'
		// Here lies the not-yet-implemented method 'IsEdgeSlot'
		// Here lies the not-yet-implemented method 'FindSlots'
		// Here lies the not-yet-implemented method 'IsLeftEdgeSlot'
		// Here lies the not-yet-implemented method 'IsRightEdgeSlot'
		// Here lies the not-yet-implemented method 'GetSlotIdxToLeft'
		// Here lies the not-yet-implemented method 'GetSlotIdxToRight'
		// Here lies the not-yet-implemented method 'AllowRightTransition'
		// Here lies the not-yet-implemented method 'AllowLeftTransition'
		// Here lies the not-yet-implemented method 'GetFireLinkTo'
		// Here lies the not-yet-implemented method 'HasFireLinkTo'
		// Here lies the not-yet-implemented method 'GetSlotActions'
		// Here lies the not-yet-implemented method 'SetDisabled'
		// Here lies the not-yet-implemented method 'SetSlotEnabled'
		// Here lies the not-yet-implemented method 'NotifySlotOwnerCoverDisabled'
		// Here lies the not-yet-implemented method 'SetSlotPlayerOnly'
		// Here lies the not-yet-implemented method 'OnModifyCover'
		// Here lies the not-yet-implemented method 'AutoAdjustSlot'
		// Here lies the not-yet-implemented method 'IsEnabled'
		// Here lies the not-yet-implemented method 'OnToggle'
		// Here lies the not-yet-implemented method 'CreateCheckpointRecord'
		// Here lies the not-yet-implemented method 'ApplyCheckpointRecord'
		// Here lies the not-yet-implemented method 'ShutDown'
		// Here lies the not-yet-implemented method 'GetSwatTurnTarget'
		// Here lies the not-yet-implemented method 'BreakFracturedMeshes'
		// Here lies the not-yet-implemented method 'AddCoverSlot'
		// Here lies the not-yet-implemented method 'GetDebugString'
		// Here lies the not-yet-implemented method 'GetLocationDescription'
		// Here lies the not-yet-implemented method 'GetDebugAbbrev'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
