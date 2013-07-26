#pragma once
#include "Engine.UIDataStore.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIRoot.UIDataStoreBinding." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UIRoot.UIDataStoreBinding." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStoreBinding
	{
	public:
		ADD_OBJECT(UIDataStore, ResolvedDataStore)
		ADD_VAR(::NameProperty, DataStoreField, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DataStoreName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BindingIndex, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MarkupString, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RequiredFieldType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
