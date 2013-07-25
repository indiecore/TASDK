#pragma once
#include "TribesGame__TrDevice_ConstantFire.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_RepairTool." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDevice_RepairTool." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDevice_RepairTool : public TrDevice_ConstantFire
	{
	public:
		ADD_STRUCT(::VectorProperty, m_Location, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_Tangent, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fTargetHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDisplayOn, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bIsBehindView, 0x1)
		ADD_VAR(::FloatProperty, m_fVehicleRepairPercentage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPawnRepairPercentage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRepairPercentage, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'CanActorBeRepaired'
		// Here lies the not-yet-implemented method 'GetActorHealth'
		// Here lies the not-yet-implemented method 'GetAmmoCount'
		// Here lies the not-yet-implemented method 'OnEndConstantFire'
		// Here lies the not-yet-implemented method 'OnStartConstantFire'
		// Here lies the not-yet-implemented method 'InstantFire'
		// Here lies the not-yet-implemented method 'ProcessInstantHit_Internal'
		// Here lies the not-yet-implemented method 'GetRepairEndAndTangent'
		// Here lies the not-yet-implemented method 'KillRepairEffect'
		// Here lies the not-yet-implemented method 'HasViewModeSwitched'
		// Here lies the not-yet-implemented method 'SpawnRepairEffect'
		// Here lies the not-yet-implemented method 'UpdateRepairEffect'
		// Here lies the not-yet-implemented method 'UpdateDamageMaterial'
		// Here lies the not-yet-implemented method 'ModifyInstantHitDamage'
		// Here lies the not-yet-implemented method 'HasAnyAmmo'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
