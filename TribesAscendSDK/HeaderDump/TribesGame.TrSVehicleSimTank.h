#pragma once
#include "Engine.SVehicleSimTank.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSVehicleSimTank." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSVehicleSimTank : public SVehicleSimTank
	{
	public:
		ADD_VAR(::FloatProperty, m_fVelocityChangeDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastDirectionNudgeTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
