#pragma once
#include "Engine.UIDataStore_InputAlias.UIInputKeyData.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIDataStore_InputAlias.UIDataStoreInputAlias." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UIDataStore_InputAlias.UIDataStoreInputAlias." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataStoreInputAlias
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<UIInputKeyData>, PlatformInputKeys, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AliasName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
