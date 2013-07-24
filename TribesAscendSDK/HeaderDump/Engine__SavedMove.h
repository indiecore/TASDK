#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SavedMove." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SavedMove." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SavedMove." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SavedMove : public Object
	{
	public:
		ADD_VAR(::FloatProperty, TimeStamp, 0xFFFFFFFF)
		ADD_OBJECT(SavedMove, NextMove)
		ADD_STRUCT(::VectorProperty, Acceleration, 0xFFFFFFFF
		ADD_OBJECT(Actor, EndBase)
		ADD_STRUCT(::VectorProperty, SavedRelativeLocation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, SavedLocation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, SavedVelocity, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bForceRMVelocity, 0x20)
		ADD_VAR(::FloatProperty, Delta, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DoubleClickMove, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StartVelocity, 0xFFFFFFFF
		ADD_OBJECT(Actor, StartBase)
		ADD_STRUCT(::VectorProperty, StartFloor, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, Rotation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, RootMotionInterpCurveLastValue, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, RootMotionInterpCurrentTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AccelDotThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CustomTimeDilation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RMVelocity, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, StartRelativeLocation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, StartLocation, 0xFFFFFFFF
		ADD_VAR(::ByteProperty, RootMotionMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SavedPhysics, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRootMotionFromInterpCurve, 0x80)
		ADD_VAR(::BoolProperty, bForceMaxAccel, 0x40)
		ADD_VAR(::BoolProperty, bPreciseDestination, 0x10)
		ADD_VAR(::BoolProperty, bDoubleJump, 0x8)
		ADD_VAR(::BoolProperty, bPressedJump, 0x4)
		ADD_VAR(::BoolProperty, bDuck, 0x2)
		ADD_VAR(::BoolProperty, bRun, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
