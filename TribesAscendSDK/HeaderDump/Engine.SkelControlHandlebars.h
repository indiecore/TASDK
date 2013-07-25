#pragma once
#include "Engine.SkelControlSingleBone.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkelControlHandlebars." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SkelControlHandlebars : public SkelControlSingleBone
	{
	public:
		ADD_VAR(::IntProperty, SteerWheelBoneIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bInvertRotation, 0x1)
		ADD_VAR(::NameProperty, WheelBoneName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, HandlebarRotateAxis, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, WheelRollAxis, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
