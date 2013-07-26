#pragma once
#include "Engine.UIRoot.RawInputKeyEventData.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIDataStore_InputAlias.UIInputKeyData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UIDataStore_InputAlias.UIInputKeyData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIInputKeyData
	{
	public:
		ADD_VAR(::StrProperty, ButtonFontMarkupString, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawInputKeyEventData>, InputKeyData, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
