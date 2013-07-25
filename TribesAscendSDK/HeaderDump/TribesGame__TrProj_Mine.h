#pragma once
#include "TribesGame__TrProjectile.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_Mine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_Mine." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_Mine : public TrProjectile
	{
	public:
		ADD_OBJECT(PlayerReplicationInfo, r_OwnerPRI)
		ADD_VAR(::IntProperty, m_nIconStackId, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_MarkerMIC)
		ADD_VAR(::IntProperty, m_nMarkerOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fShowHeaderUntil, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPostRenderTraceTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_sScreenName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nNumBouncesBeforeDetonateObsolete, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nNumBounces, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxFloorZ, 0xFFFFFFFF)
		ADD_OBJECT(TrMineCollisionProxy, m_CollisionProxy)
		ADD_VAR(::FloatProperty, m_fDetonationHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDetonationRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDeploySeconds, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bIsPostRendered, 0x10)
		ADD_VAR(::BoolProperty, bPostRenderTraceSucceeded, 0x8)
		ADD_VAR(::BoolProperty, m_bDrawOwnerName, 0x4)
		ADD_VAR(::BoolProperty, m_bUsesDetonationProxy, 0x2)
		ADD_VAR(::BoolProperty, m_bArmed, 0x1)
		ADD_OBJECT(SoundCue, WallImpactSound)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
