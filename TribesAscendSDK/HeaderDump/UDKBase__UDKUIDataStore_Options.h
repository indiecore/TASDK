#pragma once
#include "Engine__UIDataStore_GameResource.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKUIDataStore_Options." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataStore_Options : public UIDataStore_GameResource
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.MultiMap_Mirror' for the property named 'OptionProviders'!
		// Here lies the not-yet-implemented method 'ClearSet'
		// Here lies the not-yet-implemented method 'AppendToSet'
		// Here lies the not-yet-implemented method 'GetSet'
	};
}
#undef ADD_STRUCT
