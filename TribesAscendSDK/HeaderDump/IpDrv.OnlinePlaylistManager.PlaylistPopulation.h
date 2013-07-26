#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlinePlaylistManager.PlaylistPopulation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PlaylistPopulation
	{
	public:
		ADD_VAR(::IntProperty, RegionTotal, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, WorldwideTotal, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlaylistId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
