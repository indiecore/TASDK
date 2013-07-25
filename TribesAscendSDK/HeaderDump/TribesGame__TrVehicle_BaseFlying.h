#pragma once
#include "TribesGame__TrVehicle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVehicle_BaseFlying." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrVehicle_BaseFlying : public TrVehicle
	{
	public:
		ADD_VAR(::BoolProperty, m_bCanAutoLevelVehicle, 0x2)
		ADD_VAR(::BoolProperty, m_bFreeLook, 0x1)
		ADD_VAR(::FloatProperty, m_fBoostThrustInvDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBoostThrustBuildUp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fThrustInvDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fThrustBuildUp, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
