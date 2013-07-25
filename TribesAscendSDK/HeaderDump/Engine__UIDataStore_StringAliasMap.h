#pragma once
#include "Engine__UIDataStore_StringBase.h"
#include "Engine__LocalPlayer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataStore_StringAliasMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataStore_StringAliasMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataStore_StringAliasMap : public UIDataStore_StringBase
	{
	public:
		ADD_VAR(::IntProperty, PlayerIndex, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'MenuInputSets'!
		// Here lies the not-yet-implemented method 'GetPlayerOwner'
		// Here lies the not-yet-implemented method 'FindMappingWithFieldName'
		// Here lies the not-yet-implemented method 'GetStringWithFieldName'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
