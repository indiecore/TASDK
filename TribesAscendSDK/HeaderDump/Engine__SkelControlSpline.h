#pragma once
#include "Engine__SkelControlBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkelControlSpline." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SkelControlSpline : public SkelControlBase
	{
	public:
		ADD_VAR(::FloatProperty, StartSplineTension, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EndSplineTension, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bInvertSplineBoneAxis, 0x1)
		ADD_VAR(::ByteProperty, BoneRotMode, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SplineLength, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SplineBoneAxis, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
