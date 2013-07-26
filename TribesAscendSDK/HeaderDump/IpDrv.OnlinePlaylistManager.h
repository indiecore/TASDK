#pragma once
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#include "Engine.OnlineGameSettings.h"
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
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_FTickableObject, 0xFFFFFFFF)
		void OnPlaylistPopulationDataUpdated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.OnPlaylistPopulationDataUpdated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReadPlaylistComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.OnReadPlaylistComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DownloadPlaylist()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.DownloadPlaylist");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DetermineFilesToDownload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.DetermineFilesToDownload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReadTitleFileComplete(bool bWasSuccessful, ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.OnReadTitleFileComplete");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bWasSuccessful;
			*(ScriptArray<wchar_t>*)(params + 4) = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FinalizePlaylistObjects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.FinalizePlaylistObjects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class OnlineGameSettings* GetGameSettings(int PlaylistId, int GameSettingsId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.GetGameSettings");
			byte* params = (byte*)malloc(12);
			*(int*)params = PlaylistId;
			*(int*)(params + 4) = GameSettingsId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class OnlineGameSettings**)(params + 8);
			free(params);
			return returnVal;
		}
		bool HasAnyGameSettings(int PlaylistId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.HasAnyGameSettings");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlaylistId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool PlaylistSupportsDedicatedServers(int PlaylistId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.PlaylistSupportsDedicatedServers");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlaylistId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void GetTeamInfoFromPlaylist(int PlaylistId, int& TeamSize, int& TeamCount, int& MaxPartySize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.GetTeamInfoFromPlaylist");
			byte* params = (byte*)malloc(16);
			*(int*)params = PlaylistId;
			*(int*)(params + 4) = TeamSize;
			*(int*)(params + 8) = TeamCount;
			*(int*)(params + 12) = MaxPartySize;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			TeamSize = *(int*)(params + 4);
			TeamCount = *(int*)(params + 8);
			MaxPartySize = *(int*)(params + 12);
			free(params);
		}
		void GetLoadBalanceIdFromPlaylist(int PlaylistId, int& LoadBalanceId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.GetLoadBalanceIdFromPlaylist");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlaylistId;
			*(int*)(params + 4) = LoadBalanceId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			LoadBalanceId = *(int*)(params + 4);
			free(params);
		}
		bool IsPlaylistArbitrated(int PlaylistId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.IsPlaylistArbitrated");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlaylistId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetUrlFromPlaylist(int PlaylistId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.GetUrlFromPlaylist");
			byte* params = (byte*)malloc(16);
			*(int*)params = PlaylistId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		void GetMapCycleFromPlaylist(int PlaylistId, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& MapCycle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.GetMapCycleFromPlaylist");
			byte* params = (byte*)malloc(16);
			*(int*)params = PlaylistId;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = MapCycle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			MapCycle = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		ScriptClass* GetInventorySwapFromPlaylist(int PlaylistId, ScriptClass* SourceInventory)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.GetInventorySwapFromPlaylist");
			byte* params = (byte*)malloc(12);
			*(int*)params = PlaylistId;
			*(ScriptClass**)(params + 4) = SourceInventory;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 8);
			free(params);
			return returnVal;
		}
		void GetContentIdsFromPlaylist(int PlaylistId, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ContentIds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.GetContentIdsFromPlaylist");
			byte* params = (byte*)malloc(16);
			*(int*)params = PlaylistId;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = ContentIds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ContentIds = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReadPlaylistPopulation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.ReadPlaylistPopulation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReadPlaylistPopulationComplete(bool bWasSuccessful, ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.OnReadPlaylistPopulationComplete");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bWasSuccessful;
			*(ScriptArray<wchar_t>*)(params + 4) = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ParsePlaylistPopulationData(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.ParsePlaylistPopulationData");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Data = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void GetPopulationInfoFromPlaylist(int PlaylistId, int& WorldwideTotal, int& RegionTotal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.GetPopulationInfoFromPlaylist");
			byte* params = (byte*)malloc(12);
			*(int*)params = PlaylistId;
			*(int*)(params + 4) = WorldwideTotal;
			*(int*)(params + 8) = RegionTotal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			WorldwideTotal = *(int*)(params + 4);
			RegionTotal = *(int*)(params + 8);
			free(params);
		}
		void SendPlaylistPopulationUpdate(int NumPlayers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.SendPlaylistPopulationUpdate");
			byte* params = (byte*)malloc(4);
			*(int*)params = NumPlayers;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReadDataCenterId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.ReadDataCenterId");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReadDataCenterIdComplete(bool bWasSuccessful, ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.OnReadDataCenterIdComplete");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bWasSuccessful;
			*(ScriptArray<wchar_t>*)(params + 4) = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ParseDataCenterId(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlinePlaylistManager.ParseDataCenterId");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Data = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
