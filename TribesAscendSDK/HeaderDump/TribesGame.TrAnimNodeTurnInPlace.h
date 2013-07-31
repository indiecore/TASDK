#pragma once
#include "Engine.AnimNodeBlend.h"
#include "Core.Object.h"
#include "TribesGame.TrAnimNodeAimOffset.h"
#include "TribesGame.TrAnimNodeTurnInPlace_Player.h"
#include "TribesGame.TrPawn.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeTurnInPlace : public AnimNodeBlend
	{
	public:
		enum ForcedTransitionAngle : byte
		{
			FTA_NONE = 0,
			FTA_90 = 1,
			FTA_180 = 2,
			FTA_MAX = 3,
		};
		struct RotTransitionInfo
		{
		public:
			ADD_STRUCT(ScriptName, TransName, 4)
			ADD_STRUCT(float, RotationOffset, 0)
		};
		ADD_STRUCT(ScriptArray<class TrAnimNodeAimOffset*>, m_OffsetNodes, 296)
		ADD_STRUCT(ScriptArray<TrAnimNodeTurnInPlace::RotTransitionInfo>, m_RotTransitions, 308)
		ADD_STRUCT(ScriptArray<class TrAnimNodeTurnInPlace_Player*>, m_PlayerNodes, 348)
		ADD_STRUCT(Rotator, m_InterpRotation, 368)
		ADD_STRUCT(float, m_fTurnInterpTime, 364)
		ADD_STRUCT(float, m_fIgnoredTransitionTime, 360)
		ADD_STRUCT(float, m_RemainingInterpolationTime, 344)
		ADD_STRUCT(float, m_fInterpolationTime, 340)
		ADD_STRUCT(float, m_fChooseNewTransitionPercent, 336)
		ADD_STRUCT(TrAnimNodeTurnInPlace::ForcedTransitionAngle, m_ForcedTransitionAngle, 332)
		ADD_STRUCT(float, m_fTransitionThresholdAngle, 328)
		ADD_STRUCT(int, m_nCurrentTransitionIndex, 324)
		ADD_STRUCT(float, m_fTransitionBlendTime, 320)
		ADD_STRUCT(float, m_fRelativeOffset, 292)
		ADD_STRUCT(int, m_nPitchOffset, 288)
		ADD_STRUCT(int, m_nYawOffset, 284)
		ADD_STRUCT(int, m_nLastRootBoneYaw, 280)
		ADD_STRUCT(float, m_fPawnRotationRate, 276)
		ADD_STRUCT(int, m_nLastPawnPitch, 272)
		ADD_STRUCT(int, m_nLastPawnYaw, 268)
		ADD_BOOL(m_bDisableAllTurning, 264, 0x8000)
		ADD_BOOL(m_bConstrictIdleYawOffset, 264, 0x4000)
		ADD_BOOL(m_bUse180ShortestRoute, 264, 0x2000)
		ADD_BOOL(m_bUsePawnRotationAtZeroVelocity, 264, 0x1000)
		ADD_BOOL(m_bTurnTowardsVelocity, 264, 0x800)
		ADD_BOOL(m_bOnlyUpdateRotationWhenMoving, 264, 0x400)
		ADD_BOOL(m_bIgnoreTransitionAnimations, 264, 0x200)
		ADD_BOOL(m_bAlwaysUpdateYawOffset, 264, 0x100)
		ADD_BOOL(m_bMirrorOffsetWhenPawnMirrored, 264, 0x80)
		ADD_BOOL(m_bOverrideInterpolationTime, 264, 0x40)
		ADD_BOOL(m_bCanChooseNewTransition, 264, 0x20)
		ADD_BOOL(m_bPlayingTurnTransition, 264, 0x10)
		ADD_BOOL(m_bDelayBlendOutToPlayAnim, 264, 0x8)
		ADD_BOOL(m_bDisableRotation, 264, 0x4)
		ADD_BOOL(m_bRootRotInitialized, 264, 0x2)
		ADD_BOOL(m_bInitialized, 264, 0x1)
		ADD_OBJECT(TrPawn, m_TrPawn, 260)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
