#pragma once
#include "Engine__UIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlinePlaylistProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlinePlaylistProvider : public UIResourceDataProvider
	{
	public:
		ADD_VAR(::IntProperty, Priority, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsArbitrated, 0x1)
		ADD_VAR(::StrProperty, DisplayName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlaylistId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
