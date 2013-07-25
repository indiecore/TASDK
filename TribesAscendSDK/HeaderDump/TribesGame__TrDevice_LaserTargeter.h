#pragma once
#include "TribesGame__TrDevice_ConstantFire.h"
#include "Engine__Actor.h"
#include "TribesGame__TrCallIn.h"
#include "Engine__SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_LaserTargeter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDevice_LaserTargeter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_LaserTargeter." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_LaserTargeter : public TrDevice_ConstantFire
	{
	public:
		ADD_VAR(::ByteProperty, r_ActiveCallin, 0xFFFFFFFF)
		ADD_OBJECT(TrCallIn, r_CallIns)
		ADD_STRUCT(::VectorProperty, m_LastTargetPos, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, m_LastOwnerRot, 0xFFFFFFFF
		ADD_OBJECT(SoundCue, m_CallInConfirmation)
		ADD_VAR(::ByteProperty, m_PrevActiveCallin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCallInEndTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'CalcHUDAimChargePercent'
		// Here lies the not-yet-implemented method 'IsValidCallIn'
		// Here lies the not-yet-implemented method 'IsValidTargetLocation'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'UpdateCallins'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'CanFireCallIn'
		// Here lies the not-yet-implemented method 'SetActiveCallIn'
		// Here lies the not-yet-implemented method 'OnEndConstantFire'
		// Here lies the not-yet-implemented method 'OnStartConstantFire'
		// Here lies the not-yet-implemented method 'GetLaserStartAndEnd'
		// Here lies the not-yet-implemented method 'KillLaserEffect'
		// Here lies the not-yet-implemented method 'SpawnLaserEffect'
		// Here lies the not-yet-implemented method 'UpdateLaserEffect'
		// Here lies the not-yet-implemented method 'CallInConfirmed'
		// Here lies the not-yet-implemented method 'ServerPerformCallIn'
		// Here lies the not-yet-implemented method 'UpdateTarget'
		// Here lies the not-yet-implemented method 'GetTraceOwner'
		// Here lies the not-yet-implemented method 'GetAmmoCount'
		// Here lies the not-yet-implemented method 'UpdateCreditMaterial'
		// Here lies the not-yet-implemented method 'PlayWeaponEquip'
		// Here lies the not-yet-implemented method 'UpdateCallInMaterial'
		// Here lies the not-yet-implemented method 'UpdateWeaponMICs'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
