#pragma once
#include "Core.Object.Vector2D.h"
#include "Core.Object.Vector.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameThirdPersonCamera.CamFocusPointParams." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameThirdPersonCamera.CamFocusPointParams." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameThirdPersonCamera.CamFocusPointParams." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CamFocusPointParams
	{
	public:
		ADD_VAR(::FloatProperty, FocusPitchOffsetDeg, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIgnoreTrace, 0x4)
		ADD_VAR(::BoolProperty, bAdjustCamera, 0x2)
		ADD_VAR(::BoolProperty, bAlwaysFocus, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, InFocusFOV, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, InterpSpeedRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraFOV, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FocusWorldLoc, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, FocusBoneName, 0xFFFFFFFF)
		ADD_OBJECT(Actor, FocusActor)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
