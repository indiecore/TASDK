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
		// Here lies the not-yet-implemented method 'UploadPlayerData'
		// Here lies the not-yet-implemented method 'UploadGameplayEventsData'
		// Here lies the not-yet-implemented method 'UpdatePlaylistPopulation'
		// Here lies the not-yet-implemented method 'UploadMatchmakingStats'
	};
}
#undef ADD_VAR
