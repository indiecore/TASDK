#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.OnlinePlaylistManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.OnlinePlaylistManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlinePlaylistManager : public Object
	{
	public:
		ADD_VAR(::StrProperty, DataCenterFileName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DataCenterId, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EventsInterfaceName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrentPlaylistId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinPlaylistIdToReport, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PlaylistPopulationUpdateInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NextPlaylistPopulationUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PopulationFileName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RegionTotalPlayers, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, WorldwideTotalPlayers, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VersionNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SuccessfulCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DownloadCount, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FTickableObject'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
