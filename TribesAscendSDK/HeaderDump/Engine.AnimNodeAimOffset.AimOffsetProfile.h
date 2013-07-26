#pragma once
#include "Core.Object.Vector2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimNodeAimOffset.AimOffsetProfile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty AnimNodeAimOffset.AimOffsetProfile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AimOffsetProfile
	{
	public:
		ADD_VAR(::NameProperty, AnimName_RD, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_RC, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_RU, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_CD, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_CC, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_CU, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_LD, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_LC, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_LU, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, VerticalRange, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, HorizontalRange, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ProfileName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
