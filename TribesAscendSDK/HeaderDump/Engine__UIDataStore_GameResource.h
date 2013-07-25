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
	};
}
#undef ADD_STRUCT
