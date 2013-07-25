#pragma once
#include "Engine__AnimNodeBlend.h"
#include "TribesGame__TrPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAnimNodeTurnInPlace." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrAnimNodeTurnInPlace." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeTurnInPlace." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeTurnInPlace : public AnimNodeBlend
	{
	public:
		ADD_STRUCT(::RotatorProperty, m_InterpRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fTurnInterpTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fIgnoredTransitionTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_RemainingInterpolationTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInterpolationTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fChooseNewTransitionPercent, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_ForcedTransitionAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTransitionThresholdAngle, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCurrentTransitionIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTransitionBlendTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRelativeOffset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPitchOffset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nYawOffset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastRootBoneYaw, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPawnRotationRate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastPawnPitch, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastPawnYaw, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bDisableAllTurning, 0x8000)
		ADD_VAR(::BoolProperty, m_bConstrictIdleYawOffset, 0x4000)
		ADD_VAR(::BoolProperty, m_bUse180ShortestRoute, 0x2000)
		ADD_VAR(::BoolProperty, m_bUsePawnRotationAtZeroVelocity, 0x1000)
		ADD_VAR(::BoolProperty, m_bTurnTowardsVelocity, 0x800)
		ADD_VAR(::BoolProperty, m_bOnlyUpdateRotationWhenMoving, 0x400)
		ADD_VAR(::BoolProperty, m_bIgnoreTransitionAnimations, 0x200)
		ADD_VAR(::BoolProperty, m_bAlwaysUpdateYawOffset, 0x100)
		ADD_VAR(::BoolProperty, m_bMirrorOffsetWhenPawnMirrored, 0x80)
		ADD_VAR(::BoolProperty, m_bOverrideInterpolationTime, 0x40)
		ADD_VAR(::BoolProperty, m_bCanChooseNewTransition, 0x20)
		ADD_VAR(::BoolProperty, m_bPlayingTurnTransition, 0x10)
		ADD_VAR(::BoolProperty, m_bDelayBlendOutToPlayAnim, 0x8)
		ADD_VAR(::BoolProperty, m_bDisableRotation, 0x4)
		ADD_VAR(::BoolProperty, m_bRootRotInitialized, 0x2)
		ADD_VAR(::BoolProperty, m_bInitialized, 0x1)
		ADD_OBJECT(TrPawn, m_TrPawn)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
