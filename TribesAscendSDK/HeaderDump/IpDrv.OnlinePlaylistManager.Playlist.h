#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlinePlaylistManager.Playlist." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Playlist
	{
	public:
		ADD_VAR(::BoolProperty, bDisableDedicatedServerSearches, 0x2)
		ADD_VAR(::BoolProperty, bIsArbitrated, 0x1)
		ADD_VAR(::StrProperty, URL, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Name, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxPartySize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TeamCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TeamSize, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LocalizationString, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LoadBalanceId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlaylistId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
