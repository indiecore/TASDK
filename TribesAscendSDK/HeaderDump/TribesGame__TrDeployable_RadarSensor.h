#pragma once
#include "TribesGame__TrDeployable_Sensor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployable_RadarSensor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDeployable_RadarSensor : public TrDeployable_Sensor
	{
	public:
		ADD_VAR(::FloatProperty, m_fBlipIntervalTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
