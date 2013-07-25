#pragma once
#include "Engine__UIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlinePlaylistGameTypeProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlinePlaylistGameTypeProvider : public UIResourceDataProvider
	{
	public:
		ADD_VAR(::IntProperty, GameTypeId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DisplayName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, PlaylistGameTypeName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
