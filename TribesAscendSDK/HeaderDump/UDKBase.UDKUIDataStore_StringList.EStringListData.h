#pragma once
#include "UDKBase.UDKUIDataProvider_StringArray.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKUIDataStore_StringList.EStringListData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKUIDataStore_StringList.EStringListData." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class EStringListData
	{
	public:
		ADD_OBJECT(UDKUIDataProvider_StringArray, DataProvider)
		ADD_VAR(::IntProperty, DefaultValueIndex, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CurrentValue, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ColumnHeaderText, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, Tag, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
