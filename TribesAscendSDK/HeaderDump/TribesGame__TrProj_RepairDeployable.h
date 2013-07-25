#pragma once
#include "TribesGame__TrProj_Mine.h"
#include "Engine__SoundCue.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_RepairDeployable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_RepairDeployable." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_RepairDeployable : public TrProj_Mine
	{
	public:
		ADD_VAR(::FloatProperty, m_fTickFrequency, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeSinceLastTick, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, RepairBeamSound)
		ADD_VAR(::FloatProperty, m_fVehicleRepairPercentage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRepairPercentage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRepairBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRepairRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCheckNearbyActorsFrequency, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'InitProjectile'
		// Here lies the not-yet-implemented method 'ArmedTimer'
		// Here lies the not-yet-implemented method 'HitWall'
		// Here lies the not-yet-implemented method 'CheckRepair'
		// Here lies the not-yet-implemented method 'Explode'
		// Here lies the not-yet-implemented method 'DetonateObsolete'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
