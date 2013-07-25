#pragma once
#include "Engine__UIDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataProvider_SettingsArray." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataProvider_SettingsArray." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataProvider_SettingsArray." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataProvider_SettingsArray : public UIDataProvider
	{
	public:
		ADD_VAR(::StrProperty, ColumnHeaderText, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SettingsName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SettingsId, 0xFFFFFFFF)
		ADD_OBJECT(Settings, Settings)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementCellProvider'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementProvider'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
