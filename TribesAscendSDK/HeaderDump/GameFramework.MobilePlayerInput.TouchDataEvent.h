#pragma once
#include "Core.Object.Double.h"
#include "Core.Object.Vector2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MobilePlayerInput.TouchDataEvent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty MobilePlayerInput.TouchDataEvent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TouchDataEvent
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Double>, DeviceTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, Location, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, EventType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
