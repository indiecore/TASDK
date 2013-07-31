#pragma once
#include "Engine.UIResourceDataProvider.h"
#include "Engine.UIRoot.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider_MenuItem : public UIResourceDataProvider
	{
	public:
		enum EMenuOptionType : byte
		{
			MENUOT_ComboReadOnly = 0,
			MENUOT_ComboNumeric = 1,
			MENUOT_CheckBox = 2,
			MENUOT_Slider = 3,
			MENUOT_Spinner = 4,
			MENUOT_EditBox = 5,
			MENUOT_CollectionCheckBox = 6,
			MENUOT_CollapsingList = 7,
			MENUOT_MAX = 8,
		};
		ADD_STRUCT(ScriptArray<ScriptName>, OptionSet, 128)
		ADD_STRUCT(ScriptArray<ScriptName>, SchemaCellFields, 236)
		ADD_STRUCT(ScriptString*, IniName, 248)
		ADD_STRUCT(UIRoot::UIRangeData, RangeData, 216)
		ADD_STRUCT(int, EditBoxMaxLength, 212)
		ADD_BOOL(bRemoveOnPS3, 208, 0x100)
		ADD_BOOL(bRemoveOnPC, 208, 0x80)
		ADD_BOOL(bRemoveOn360, 208, 0x40)
		ADD_BOOL(bSearchAllInis, 208, 0x20)
		ADD_BOOL(bOfflineOnly, 208, 0x10)
		ADD_BOOL(bOnlineOnly, 208, 0x8)
		ADD_BOOL(bKeyboardOrMouseOption, 208, 0x4)
		ADD_BOOL(bNumericCombo, 208, 0x2)
		ADD_BOOL(bEditableCombo, 208, 0x1)
		ADD_STRUCT(ScriptString*, Description, 196)
		ADD_STRUCT(ScriptString*, CustomFriendlyName, 184)
		ADD_STRUCT(ScriptString*, FriendlyName, 172)
		ADD_STRUCT(ScriptName, RequiredGameMode, 164)
		ADD_STRUCT(ScriptString*, DescriptionMarkup, 152)
		ADD_STRUCT(ScriptString*, DataStoreMarkup, 140)
		ADD_STRUCT(UIDataProvider_MenuItem::EMenuOptionType, OptionType, 124)
		bool IsFiltered()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28149);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
