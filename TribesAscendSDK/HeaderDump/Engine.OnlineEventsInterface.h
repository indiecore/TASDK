#pragma once
#include "Core.Interface.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "Engine.OnlinePlayerStorage.h"
#include "Engine.OnlineProfileSettings.h"
namespace UnrealScript
{
	class OnlineEventsInterface : public Interface
	{
	public:
		bool UploadPlayerData(UniqueNetId UniqueId, ScriptArray<wchar_t> PlayerNick, class OnlineProfileSettings* ProfileSettings, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineEventsInterface.UploadPlayerData");
			byte* params = (byte*)malloc(32);
			*(UniqueNetId*)params = UniqueId;
			*(ScriptArray<wchar_t>*)(params + 8) = PlayerNick;
			*(class OnlineProfileSettings**)(params + 20) = ProfileSettings;
			*(class OnlinePlayerStorage**)(params + 24) = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool UploadGameplayEventsData(UniqueNetId UniqueId, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Payload)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineEventsInterface.UploadGameplayEventsData");
			byte* params = (byte*)malloc(24);
			*(UniqueNetId*)params = UniqueId;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineEventsInterface.UpdatePlaylistPopulation");
			byte* params = (byte*)malloc(12);
			*(int*)params = PlaylistId;
			*(int*)(params + 4) = NumPlayers;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
