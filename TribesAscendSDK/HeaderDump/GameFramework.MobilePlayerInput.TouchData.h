#pragma once
#include "Core.Object.Vector2D.h"
#include "GameFramework.MobileInputZone.h"
#include "Core.Object.Double.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MobilePlayerInput.TouchData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty MobilePlayerInput.TouchData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty MobilePlayerInput.TouchData." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TouchData
	{
	public:
		ADD_VAR(::BoolProperty, bInUse, 0x1)
		ADD_VAR(::ByteProperty, State, 0xFFFFFFFF)
		ADD_OBJECT(MobileInputZone, Zone)
		ADD_VAR(::IntProperty, Handle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastActiveTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MoveDeltaTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Double>, MoveEventDeviceTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TouchDuration, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Double>, InitialDeviceTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TotalMoveDistance, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, Location, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
