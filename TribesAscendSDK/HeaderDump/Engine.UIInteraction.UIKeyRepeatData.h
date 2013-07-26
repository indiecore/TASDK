#pragma once
#include "Core.Object.Double.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIInteraction.UIKeyRepeatData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UIInteraction.UIKeyRepeatData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIKeyRepeatData
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Double>, NextRepeatTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, CurrentRepeatKey, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
