#pragma once
#include "Engine__UIDataStore_GameResource.h"
#include "Engine__UIDataStore.h"
#include "Engine__LocalPlayer.h"
#include "Engine__UIDataProvider_OnlineProfileSettings.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataStore_DynamicResource." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataStore_DynamicResource." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStore_DynamicResource : public UIDataStore
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.MultiMap_Mirror' for the property named 'ResourceProviders'!
		ADD_OBJECT(UIDataStore_GameResource, GameResourceDataStore)
		ADD_OBJECT(UIDataProvider_OnlineProfileSettings, ProfileProvider)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementProvider'!
		// Here lies the not-yet-implemented method 'FindProviderTypeIndex'
		// Here lies the not-yet-implemented method 'GenerateProviderAccessTag'
		// Here lies the not-yet-implemented method 'GetProviderCount'
		// Here lies the not-yet-implemented method 'GetResourceProviders'
		// Here lies the not-yet-implemented method 'GetResourceProviderFields'
		// Here lies the not-yet-implemented method 'GetProviderFieldValue'
		// Here lies the not-yet-implemented method 'FindProviderIndexByFieldValue'
		// Here lies the not-yet-implemented method 'OnLoginChange'
		// Here lies the not-yet-implemented method 'Registered'
		// Here lies the not-yet-implemented method 'Unregistered'
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
