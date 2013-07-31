#pragma once
#include "Engine.UIDataProvider.h"
#include "Engine.Settings.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UIDataProvider_SettingsArray : public UIDataProvider
	{
	public:
		ADD_STRUCT(ScriptArray<Settings::IdToStringMapping>, Values, 124)
		ADD_STRUCT(ScriptString*, ColumnHeaderText, 112)
		ADD_STRUCT(ScriptName, SettingsName, 104)
		ADD_STRUCT(int, SettingsId, 100)
		ADD_OBJECT(Settings, Settings, 96)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementCellProvider, 92)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementProvider, 88)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
