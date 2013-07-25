#pragma once
#include "Engine__UIDataStore_GameResource.h"
#include "Engine__UIDataProvider.h"
#include "Engine__LocalPlayer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataStore_MenuItems." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataStore_MenuItems." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataStore_MenuItems : public UIDataStore_GameResource
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.MultiMap_Mirror' for the property named 'OptionProviders'!
		ADD_VAR(::NameProperty, CurrentGameSettingsTag, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'ClearSet'
		// Here lies the not-yet-implemented method 'AppendToSet'
		// Here lies the not-yet-implemented method 'GetSet'
		// Here lies the not-yet-implemented method 'OnGameSettingsChanged'
		// Here lies the not-yet-implemented method 'Registered'
		// Here lies the not-yet-implemented method 'Unregistered'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
