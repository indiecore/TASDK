#pragma once
#include "UDKBase.UDKUIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKUIDataProvider_MapInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataProvider_MapInfo : public UDKUIResourceDataProvider
	{
	public:
		ADD_VAR(::StrProperty, PreviewImageMarkup, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NumPlayers, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MapName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MapId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
