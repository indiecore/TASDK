#pragma once
#include "TribesGame__TrGameObjective.h"
#include "TribesGame__TrPawn.h"
#include "Engine__MaterialInstanceConstant.h"
#include "TribesGame__TrPlayerController.h"
#include "Engine__SkelControlSingleBone.h"
#include "Engine__Actor.h"
#include "Engine__Canvas.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCaHCapturePoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrCaHCapturePoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCaHCapturePoint." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCaHCapturePoint : public TrGameObjective
	{
	public:
		ADD_VAR(::FloatProperty, m_HoldTheLineAccoladeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fNearbyPawnCheckTime, 0xFFFFFFFF)
		ADD_OBJECT(TrPlayerController, m_LastCapturedBy)
		ADD_VAR(::FloatProperty, m_fPointPulseMarkerSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPointPulseMarkerTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRemainingPointPulseMarkerTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPulseMarkerSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPulseMarkerTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRemainingPulseMarkerTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_MarkerSize, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nFlashPointPulse, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_CapturePointLabel, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bIsHeld, 0x1)
		ADD_STRUCT(::VectorProperty, LastCameraPos, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LastCameraDir, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LastScreenLoc, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fInfluenceRadiusSize, 0xFFFFFFFF)
		ADD_OBJECT(SkelControlSingleBone, m_SkyHologramSkelControl)
		ADD_VAR(::FloatProperty, m_fSkyHologramScaleDS, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkyHologramScaleBE, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkyHologramScaleOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vSkyHologramOffsetDS, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vSkyHologramOffsetBE, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fSkyHologramOffsetZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkyHologramOffsetY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkyHologramOffsetX, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_DiamondSwordHologramMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_BloodEagleHologramMIC)
		ADD_VAR(::StrProperty, m_sCapturePointName, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'PulseMarker'
		// Here lies the not-yet-implemented method 'PointPulseMarker'
		// Here lies the not-yet-implemented method 'UpdateHologramVisibility'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'Touch'
		// Here lies the not-yet-implemented method 'OnPawnTouched'
		// Here lies the not-yet-implemented method 'PostCapturePointTimer'
		// Here lies the not-yet-implemented method 'AwardPointTimer'
		// Here lies the not-yet-implemented method 'ShouldPostRenderForCaH'
		// Here lies the not-yet-implemented method 'GetScreenName'
		// Here lies the not-yet-implemented method 'PostRenderFor'
		// Here lies the not-yet-implemented method 'CheckNearbyPlayersTimer'
		// Here lies the not-yet-implemented method 'IsPawnConsideredNearby'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
