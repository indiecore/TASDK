#pragma once
#include "TribesGame__TrDevice.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_SaberLauncher." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_SaberLauncher." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_SaberLauncher : public TrDevice
	{
	public:
		ADD_VAR(::BoolProperty, r_bTargetLocked, 0x1)
		ADD_OBJECT(TrPlayerController, m_TargetController)
		ADD_VAR(::ByteProperty, r_nFired, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLockingTargetTimestamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeBeforeVictimKnowsMissileIsTargeting, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fGroundCheckDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPotentialTargetLockOnDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fReticuleLockOnDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLockRetainSeconds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRestoreAimHelpRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMinCosineAcquireTarget, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAcquireTargetMaxAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRetainTargetMaxAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMinCosineRetainTarget, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bDebugMode, 0x4)
		ADD_VAR(::BoolProperty, m_bRestoreAimingHelp, 0x2)
		ADD_OBJECT(Actor, m_Target)
		ADD_VAR(::FloatProperty, m_fPreLockTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTargetSightTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
