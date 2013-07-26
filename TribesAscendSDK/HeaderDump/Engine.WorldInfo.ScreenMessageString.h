#pragma once
#include "Core.Object.QWord.h"
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " WorldInfo.ScreenMessageString." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty WorldInfo.ScreenMessageString." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ScreenMessageString
	{
	public:
		ADD_STRUCT(::QWordProperty, Key, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ScreenMessage, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, DisplayColor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeToDisplay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentTimeDisplayed, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
