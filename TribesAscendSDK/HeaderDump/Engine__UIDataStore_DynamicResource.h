#pragma once
#include "Engine__UIDataStore.h"
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
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
