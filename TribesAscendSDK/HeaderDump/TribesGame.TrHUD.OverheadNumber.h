#pragma once
#include "Core.Object.Color.h"
#include "Core.Object.Vector4.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrHUD.OverheadNumber." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TrHUD.OverheadNumber." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OverheadNumber
	{
	public:
		ADD_VAR(::FloatProperty, CurrentScale, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, CurrentColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector4>, WorldSpaceLocation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RemainingTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumberValue, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
