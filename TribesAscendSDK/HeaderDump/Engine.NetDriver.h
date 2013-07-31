#pragma once
#include "Core.Subsystem.h"
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
	class NetDriver : public Subsystem
	{
	public:
		ADD_STRUCT(float, ConnectionTimeout, 96)
		ADD_STRUCT(float, InitialConnectTimeout, 100)
		ADD_STRUCT(float, KeepAliveTime, 104)
		ADD_STRUCT(float, RelevantTimeout, 108)
		ADD_STRUCT(float, SpawnPrioritySeconds, 112)
		ADD_STRUCT(float, ServerTravelPause, 116)
		ADD_STRUCT(int, MaxClientRate, 120)
		ADD_STRUCT(int, MaxInternetClientRate, 124)
		ADD_STRUCT(int, NetServerMaxTickRate, 128)
		ADD_BOOL(bClampListenServerTickRate, 132, 0x1)
		ADD_BOOL(AllowDownloads, 136, 0x1)
		ADD_BOOL(AllowPeerConnections, 140, 0x1)
		ADD_BOOL(AllowPeerVoice, 144, 0x1)
		ADD_STRUCT(int, MaxDownloadSize, 172)
		ADD_STRUCT(ScriptString*, NetConnectionClassName, 332)
		ADD_STRUCT(ScriptArray<ScriptString*>, DownloadManagers, 176)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
