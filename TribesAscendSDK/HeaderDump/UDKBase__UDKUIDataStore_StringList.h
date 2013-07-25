#pragma once
#include "Engine__UIDataStore_StringBase.h"
#include "Engine__LocalPlayer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKUIDataStore_StringList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataStore_StringList : public UIDataStore_StringBase
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementCellProvider'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementProvider'!
		// Here lies the not-yet-implemented method 'Registered'
		// Here lies the not-yet-implemented method 'GetFieldIndex'
		// Here lies the not-yet-implemented method 'AddStr'
		// Here lies the not-yet-implemented method 'InsertStr'
		// Here lies the not-yet-implemented method 'RemoveStr'
		// Here lies the not-yet-implemented method 'RemoveStrByIndex'
		// Here lies the not-yet-implemented method 'Empty'
		// Here lies the not-yet-implemented method 'FindStr'
		// Here lies the not-yet-implemented method 'GetStr'
		// Here lies the not-yet-implemented method 'GetList'
		// Here lies the not-yet-implemented method 'GetCurrentValue'
		// Here lies the not-yet-implemented method 'GetCurrentValueIndex'
		// Here lies the not-yet-implemented method 'SetCurrentValueIndex'
		// Here lies the not-yet-implemented method 'Num'
	};
}
#undef ADD_STRUCT
