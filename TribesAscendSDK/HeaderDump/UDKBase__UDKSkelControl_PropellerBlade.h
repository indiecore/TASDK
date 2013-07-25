#pragma once
#include "Engine__SkelControlSingleBone.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKSkelControl_PropellerBlade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_PropellerBlade : public SkelControlSingleBone
	{
	public:
		ADD_VAR(::FloatProperty, DesiredRotationsPerSecond, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RotationsPerSecond, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCounterClockwise, 0x1)
		ADD_VAR(::FloatProperty, SpinUpTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxRotationsPerSecond, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
