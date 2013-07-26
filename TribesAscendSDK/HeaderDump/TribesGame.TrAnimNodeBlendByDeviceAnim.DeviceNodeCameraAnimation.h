#pragma once
#include "Engine.CameraAnimInst.h"
#include "Engine.CameraAnim.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrAnimNodeBlendByDeviceAnim.DeviceNodeCameraAnimation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrAnimNodeBlendByDeviceAnim.DeviceNodeCameraAnimation." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DeviceNodeCameraAnimation
	{
	public:
		ADD_VAR(::BoolProperty, bRandomStartTime, 0x2)
		ADD_VAR(::BoolProperty, bLoop, 0x1)
		ADD_VAR(::FloatProperty, BlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Scale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Rate, 0xFFFFFFFF)
		ADD_OBJECT(CameraAnimInst, CameraAnimInstance)
		ADD_OBJECT(CameraAnim, CameraAnim)
		ADD_VAR(::IntProperty, ChildIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
