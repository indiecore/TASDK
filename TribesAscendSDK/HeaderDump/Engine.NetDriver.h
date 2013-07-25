#pragma once
#include "Core.Subsystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NetDriver." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NetDriver : public Subsystem
	{
	public:
		ADD_VAR(::FloatProperty, ConnectionTimeout, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InitialConnectTimeout, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, KeepAliveTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RelevantTimeout, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpawnPrioritySeconds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ServerTravelPause, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxClientRate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxInternetClientRate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NetServerMaxTickRate, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bClampListenServerTickRate, 0x1)
		ADD_VAR(::BoolProperty, AllowDownloads, 0x1)
		ADD_VAR(::BoolProperty, AllowPeerConnections, 0x1)
		ADD_VAR(::BoolProperty, AllowPeerVoice, 0x1)
		ADD_VAR(::IntProperty, MaxDownloadSize, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NetConnectionClassName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
