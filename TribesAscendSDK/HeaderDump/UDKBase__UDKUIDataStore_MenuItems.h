#pragma once
#include "Engine__UIDataStore_GameResource.h"
#include "UDKBase__UDKUIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKUIDataStore_MenuItems." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKUIDataStore_MenuItems." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKUIDataStore_MenuItems." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKUIDataStore_MenuItems : public UIDataStore_GameResource
	{
	public:
		ADD_VAR(::IntProperty, GameModeFilter, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, MapInfoDataProviderClass)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementCellProvider'!
		// Here lies the not-yet-implemented method 'GetProviderCount'
		// Here lies the not-yet-implemented method 'IsProviderFiltered'
		// Here lies the not-yet-implemented method 'GetAllResourceDataProviders'
		// Here lies the not-yet-implemented method 'FindValueInProviderSet'
		// Here lies the not-yet-implemented method 'GetValueFromProviderSet'
		// Here lies the not-yet-implemented method 'GetProviderSet'
		// Here lies the not-yet-implemented method 'InitializeListElementProviders'
		// Here lies the not-yet-implemented method 'RemoveListElementProvidersKey'
		// Here lies the not-yet-implemented method 'AddListElementProvidersKey'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
