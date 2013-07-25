#pragma once
#include "Engine__OnlineMatchmakingStats.h"
#include "IpDrv__MCPBase.h"
#include "Engine__OnlinePlayerStorage.h"
#include "Engine__OnlineProfileSettings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.OnlineEventsInterfaceMcp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineEventsInterfaceMcp : public MCPBase
	{
	public:
		ADD_VAR(::BoolProperty, bBinaryStats, 0x1)
		bool UploadPlayerData(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* UniqueId, ScriptArray<wchar_t> PlayerNick, class OnlineProfileSettings* ProfileSettings, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineEventsInterfaceMcp.UploadPlayerData");
			byte* params = (byte*)malloc(32);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = UniqueId;
			*(ScriptArray<wchar_t>*)(params + 8) = PlayerNick;
			*(class OnlineProfileSettings**)(params + 20) = ProfileSettings;
			*(class OnlinePlayerStorage**)(params + 24) = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool UploadGameplayEventsData(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* UniqueId, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Payload)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineEventsInterfaceMcp.UploadGameplayEventsData");
			byte* params = (byte*)malloc(24);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = UniqueId;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = Payload;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Payload = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool UpdatePlaylistPopulation(int PlaylistId, int NumPlayers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineEventsInterfaceMcp.UpdatePlaylistPopulation");
			byte* params = (byte*)malloc(12);
			*(int*)params = PlaylistId;
			*(int*)(params + 4) = NumPlayers;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool UploadMatchmakingStats(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* UniqueId, class OnlineMatchmakingStats* MMStats)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineEventsInterfaceMcp.UploadMatchmakingStats");
			byte* params = (byte*)malloc(16);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = UniqueId;
			*(class OnlineMatchmakingStats**)(params + 8) = MMStats;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
