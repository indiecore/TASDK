#pragma once
#include "TribesGame__TrVehicle_BaseFlying.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVehicle_Havoc." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrVehicle_Havoc : public TrVehicle_BaseFlying
	{
	public:
		ADD_VAR(::FloatProperty, m_fPitchAimAngleRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPitchAimAngle, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
