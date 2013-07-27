#pragma once
#include "IpDrv.MCPBase.h"
#include "Engine.OnlineMatchmakingStats.h"
#include "Engine.OnlinePlayerStorage.h"
#include "Engine.OnlineProfileSettings.h"
#include "Core.Object.h"
#include "Engine.OnlineSubsystem.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class OnlineEventsInterfaceMcp : public MCPBase
	{
	public:
		enum EEventUploadType : byte
		{
			EUT_GenericStats = 0,
			EUT_ProfileData = 1,
			EUT_MatchmakingData = 2,
			EUT_PlaylistPopulation = 3,
			EUT_MAX = 4,
		};
		class EventUploadConfig
		{
		public:
			ADD_BOOL(bUseCompression, 20, 0x1)
			ADD_STRUCT(float, TimeOut, 16)
			ADD_STRUCT(ScriptString*, UploadUrl, 4)
			ADD_STRUCT(OnlineEventsInterfaceMcp::EEventUploadType, UploadType, 0)
		};
		ADD_STRUCT(ScriptArray<OnlineEventsInterfaceMcp::EventUploadConfig>, EventUploadConfigs, 64)
		ADD_STRUCT(ScriptArray<Object::Pointer>, HttpPostObjects, 76)
		ADD_STRUCT(ScriptArray<OnlineEventsInterfaceMcp::EEventUploadType>, DisabledUploadTypes, 88)
		ADD_BOOL(bBinaryStats, 100, 0x1)
		bool UploadPlayerData(OnlineSubsystem::UniqueNetId UniqueId, ScriptString* PlayerNick, class OnlineProfileSettings* ProfileSettings, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineEventsInterfaceMcp.UploadPlayerData");
			byte params[32] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = UniqueId;
			*(ScriptString**)&params[8] = PlayerNick;
			*(class OnlineProfileSettings**)&params[20] = ProfileSettings;
			*(class OnlinePlayerStorage**)&params[24] = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool UploadGameplayEventsData(OnlineSubsystem::UniqueNetId UniqueId, ScriptArray<byte>& Payload)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineEventsInterfaceMcp.UploadGameplayEventsData");
			byte params[24] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = UniqueId;
			*(ScriptArray<byte>*)&params[8] = Payload;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Payload = *(ScriptArray<byte>*)&params[8];
			return *(bool*)&params[20];
		}
		bool UpdatePlaylistPopulation(int PlaylistId, int NumPlayers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineEventsInterfaceMcp.UpdatePlaylistPopulation");
			byte params[12] = { NULL };
			*(int*)&params[0] = PlaylistId;
			*(int*)&params[4] = NumPlayers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UploadMatchmakingStats(OnlineSubsystem::UniqueNetId UniqueId, class OnlineMatchmakingStats* MMStats)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineEventsInterfaceMcp.UploadMatchmakingStats");
			byte params[16] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = UniqueId;
			*(class OnlineMatchmakingStats**)&params[8] = MMStats;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
