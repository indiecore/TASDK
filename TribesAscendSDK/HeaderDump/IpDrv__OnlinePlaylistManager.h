#pragma once
#include "Core__Object.h"
#include "Engine__OnlineGameSettings.h"
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
		// Here lies the not-yet-implemented method 'OnPlaylistPopulationDataUpdated'
		// Here lies the not-yet-implemented method 'OnReadPlaylistComplete'
		// Here lies the not-yet-implemented method 'DownloadPlaylist'
		// Here lies the not-yet-implemented method 'DetermineFilesToDownload'
		// Here lies the not-yet-implemented method 'OnReadTitleFileComplete'
		// Here lies the not-yet-implemented method 'FinalizePlaylistObjects'
		// Here lies the not-yet-implemented method 'GetGameSettings'
		// Here lies the not-yet-implemented method 'HasAnyGameSettings'
		// Here lies the not-yet-implemented method 'PlaylistSupportsDedicatedServers'
		// Here lies the not-yet-implemented method 'GetTeamInfoFromPlaylist'
		// Here lies the not-yet-implemented method 'GetLoadBalanceIdFromPlaylist'
		// Here lies the not-yet-implemented method 'IsPlaylistArbitrated'
		// Here lies the not-yet-implemented method 'GetUrlFromPlaylist'
		// Here lies the not-yet-implemented method 'GetMapCycleFromPlaylist'
		// Here lies the not-yet-implemented method 'GetInventorySwapFromPlaylist'
		// Here lies the not-yet-implemented method 'GetContentIdsFromPlaylist'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'ReadPlaylistPopulation'
		// Here lies the not-yet-implemented method 'OnReadPlaylistPopulationComplete'
		// Here lies the not-yet-implemented method 'ParsePlaylistPopulationData'
		// Here lies the not-yet-implemented method 'GetPopulationInfoFromPlaylist'
		// Here lies the not-yet-implemented method 'SendPlaylistPopulationUpdate'
		// Here lies the not-yet-implemented method 'ReadDataCenterId'
		// Here lies the not-yet-implemented method 'OnReadDataCenterIdComplete'
		// Here lies the not-yet-implemented method 'ParseDataCenterId'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
