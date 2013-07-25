#pragma once
#include "Engine__Info.h"
#include "Engine__Controller.h"
#include "TribesGame__TrPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCallIn_CrashLandInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrCallIn_CrashLandInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCallIn_CrashLandInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCallIn_CrashLandInfo : public Info
	{
	public:
		ADD_VAR(::FloatProperty, MomentumTransfer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Damage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageRadius, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DamageTypeClass)
		ADD_STRUCT(::VectorProperty, r_CrashLandNormal, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, r_CrashLandPoint, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, r_fCrashLandTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bPodLanded, 0x1)
		ADD_OBJECT(Controller, m_Owner)
		ADD_OBJECT(ScriptClass, m_ItemToDeploy)
		// Here lies the not-yet-implemented method 'SpawnCrashLandInfo'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'InitTimer'
		// Here lies the not-yet-implemented method 'DeliveryPodLanded'
		// Here lies the not-yet-implemented method 'MoveSameTeamPawn'
		// Here lies the not-yet-implemented method 'PerformLandingDamage'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
