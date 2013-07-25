#pragma once
#include "Engine__UIDataStore.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataStore_GameResource." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataStore_GameResource : public UIDataStore
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.MultiMap_Mirror' for the property named 'ListElementProviders'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementProvider'!
		// Here lies the not-yet-implemented method 'FindProviderTypeIndex'
		// Here lies the not-yet-implemented method 'GenerateProviderAccessTag'
		// Here lies the not-yet-implemented method 'GetProviderCount'
		// Here lies the not-yet-implemented method 'GetResourceProviders'
		// Here lies the not-yet-implemented method 'GetResourceProviderFields'
		// Here lies the not-yet-implemented method 'GetProviderFieldValue'
		// Here lies the not-yet-implemented method 'FindProviderIndexByFieldValue'
	};
}
#undef ADD_STRUCT
