#pragma once
#include "Engine__UIDataProvider.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDynamicFieldProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDynamicFieldProvider : public UIDataProvider
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'RuntimeCollectionData'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'PersistentCollectionData'!
		// Here lies the not-yet-implemented method 'InitializeRuntimeFields'
		// Here lies the not-yet-implemented method 'AddField'
		// Here lies the not-yet-implemented method 'RemoveField'
		// Here lies the not-yet-implemented method 'FindFieldIndex'
		// Here lies the not-yet-implemented method 'ClearFields'
		// Here lies the not-yet-implemented method 'GetField'
		// Here lies the not-yet-implemented method 'SetField'
		// Here lies the not-yet-implemented method 'SavePersistentProviderData'
		// Here lies the not-yet-implemented method 'GetCollectionValueSchema'
		// Here lies the not-yet-implemented method 'GetCollectionValueArray'
		// Here lies the not-yet-implemented method 'SetCollectionValueArray'
		// Here lies the not-yet-implemented method 'InsertCollectionValue'
		// Here lies the not-yet-implemented method 'RemoveCollectionValue'
		// Here lies the not-yet-implemented method 'RemoveCollectionValueByIndex'
		// Here lies the not-yet-implemented method 'ReplaceCollectionValue'
		// Here lies the not-yet-implemented method 'ReplaceCollectionValueByIndex'
		// Here lies the not-yet-implemented method 'ClearCollectionValueArray'
		// Here lies the not-yet-implemented method 'GetCollectionValue'
		// Here lies the not-yet-implemented method 'FindCollectionValueIndex'
	};
}
#undef ADD_STRUCT
