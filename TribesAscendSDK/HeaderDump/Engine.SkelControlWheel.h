#pragma once
#include "Engine.SkelControlSingleBone.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkelControlWheel." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SkelControlWheel : public SkelControlSingleBone
	{
	public:
		ADD_VAR(::BoolProperty, bInvertWheelSteering, 0x2)
		ADD_VAR(::BoolProperty, bInvertWheelRoll, 0x1)
		ADD_VAR(::FloatProperty, WheelSteering, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, WheelSteeringAxis, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, WheelRollAxis, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WheelRoll, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WheelMaxRenderDisplacement, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WheelDisplacement, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
