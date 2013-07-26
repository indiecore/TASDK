#pragma once
#include "Engine.CameraAnim.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameTypes.ScreenShakeAnimStruct." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameTypes.ScreenShakeAnimStruct." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ScreenShakeAnimStruct
	{
	public:
		ADD_OBJECT(CameraAnim, Anim)
		ADD_VAR(::BoolProperty, bUseDirectionalAnimVariants, 0x1)
		ADD_OBJECT(CameraAnim, Anim_Left)
		ADD_OBJECT(CameraAnim, Anim_Right)
		ADD_OBJECT(CameraAnim, Anim_Rear)
		ADD_VAR(::FloatProperty, AnimPlayRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AnimScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AnimBlendInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AnimBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRandomSegment, 0x1)
		ADD_VAR(::FloatProperty, RandomSegmentDuration, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSingleInstance, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
