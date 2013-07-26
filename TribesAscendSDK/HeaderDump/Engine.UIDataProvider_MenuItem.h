#pragma once
#include "Engine.UIResourceDataProvider.h"
#include "Engine.UIRoot.UIRangeData.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataProvider_MenuItem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataProvider_MenuItem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider_MenuItem : public UIResourceDataProvider
	{
	public:
		ADD_VAR(::StrProperty, IniName, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UIRangeData>, RangeData, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EditBoxMaxLength, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRemoveOnPS3, 0x100)
		ADD_VAR(::BoolProperty, bRemoveOnPC, 0x80)
		ADD_VAR(::BoolProperty, bRemoveOn360, 0x40)
		ADD_VAR(::BoolProperty, bSearchAllInis, 0x20)
		ADD_VAR(::BoolProperty, bOfflineOnly, 0x10)
		ADD_VAR(::BoolProperty, bOnlineOnly, 0x8)
		ADD_VAR(::BoolProperty, bKeyboardOrMouseOption, 0x4)
		ADD_VAR(::BoolProperty, bNumericCombo, 0x2)
		ADD_VAR(::BoolProperty, bEditableCombo, 0x1)
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CustomFriendlyName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, RequiredGameMode, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DescriptionMarkup, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DataStoreMarkup, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, OptionType, 0xFFFFFFFF)
		bool IsFiltered()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_MenuItem.IsFiltered");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
