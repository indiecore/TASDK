#pragma once
#include "UDKBase__UDKUIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKUIDataProvider_MenuOption." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKUIDataProvider_MenuOption." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataProvider_MenuOption : public UDKUIResourceDataProvider
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIRangeData' for the property named 'RangeData'!
		ADD_VAR(::IntProperty, EditBoxMaxLength, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOfflineOnly, 0x10)
		ADD_VAR(::BoolProperty, bOnlineOnly, 0x8)
		ADD_VAR(::BoolProperty, bKeyboardOrMouseOption, 0x4)
		ADD_VAR(::BoolProperty, bNumericCombo, 0x2)
		ADD_VAR(::BoolProperty, bEditableCombo, 0x1)
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CustomFriendlyName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, RequiredGameMode, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DataStoreMarkup, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, OptionType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
