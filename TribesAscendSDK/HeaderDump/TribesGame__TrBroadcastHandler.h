#pragma once
#include "Engine__BroadcastHandler.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrBroadcastHandler." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrBroadcastHandler : public BroadcastHandler
	{
	public:
		ADD_VAR(::FloatProperty, m_fSpottedActorsUpdateFrequency, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'TeamBroadcastVGSCommand'
		// Here lies the not-yet-implemented method 'GlobalBroadcastVGSCommand'
		// Here lies the not-yet-implemented method 'TeamBroadcastVGSContextCommand'
		// Here lies the not-yet-implemented method 'OnActorSpotted'
		// Here lies the not-yet-implemented method 'UpdateSpottedActorsTimer'
	};
}
#undef ADD_VAR
