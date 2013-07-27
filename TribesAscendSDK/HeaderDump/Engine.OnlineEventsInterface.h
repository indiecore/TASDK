#pragma once
#include "Core.Interface.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.OnlinePlayerStorage.h"
#include "Engine.OnlineProfileSettings.h"
namespace UnrealScript
{
	class OnlineEventsInterface : public Interface
	{
	public:
		bool UploadPlayerData(OnlineSubsystem::UniqueNetId UniqueId, ScriptString* PlayerNick, class OnlineProfileSettings* ProfileSettings, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21608);
			byte params[32] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = UniqueId;
			*(ScriptString**)&params[8] = PlayerNick;
			*(class OnlineProfileSettings**)&params[20] = ProfileSettings;
			*(class OnlinePlayerStorage**)&params[24] = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool UploadGameplayEventsData(OnlineSubsystem::UniqueNetId UniqueId, ScriptArray<byte>& Payload)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21614);
			byte params[24] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = UniqueId;
			*(ScriptArray<byte>*)&params[8] = Payload;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Payload = *(ScriptArray<byte>*)&params[8];
			return *(bool*)&params[20];
		}
		bool UpdatePlaylistPopulation(int PlaylistId, int NumPlayers)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21619);
			byte params[12] = { NULL };
			*(int*)params = PlaylistId;
			*(int*)&params[4] = NumPlayers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
}
