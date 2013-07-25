#pragma once
#include "Engine.UIDataProvider.h"
#include "Engine.OnlinePlayerStorage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataProvider_OnlinePlayerStorageArray." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataProvider_OnlinePlayerStorageArray." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataProvider_OnlinePlayerStorageArray." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataProvider_OnlinePlayerStorageArray : public UIDataProvider
	{
	public:
		ADD_VAR(::StrProperty, ColumnHeaderText, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, PlayerStorageName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerStorageId, 0xFFFFFFFF)
		ADD_OBJECT(OnlinePlayerStorage, PlayerStorage)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementCellProvider'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementProvider'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
