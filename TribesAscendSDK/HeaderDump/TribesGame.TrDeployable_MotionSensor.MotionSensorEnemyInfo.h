#pragma once
#include "Core.Object.Vector.h"
#include "TribesGame.TrPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrDeployable_MotionSensor.MotionSensorEnemyInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TrDeployable_MotionSensor.MotionSensorEnemyInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrDeployable_MotionSensor.MotionSensorEnemyInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MotionSensorEnemyInfo
	{
	public:
		ADD_VAR(::FloatProperty, LastDetectedTimeStamp, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastLocation, 0xFFFFFFFF)
		ADD_OBJECT(TrPawn, SensedPawn)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
