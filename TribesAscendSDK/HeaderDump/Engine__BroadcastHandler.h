#pragma once
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__Info.h"
#include "Engine__Actor.h"
#include "Engine__PlayerController.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.BroadcastHandler." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BroadcastHandler : public Info
	{
	public:
		ADD_VAR(::BoolProperty, bMuteSpectators, 0x1)
		ADD_VAR(::IntProperty, SentText, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'UpdateSentText'
		// Here lies the not-yet-implemented method 'AllowsBroadcast'
		// Here lies the not-yet-implemented method 'BroadcastText'
		// Here lies the not-yet-implemented method 'BroadcastLocalized'
		// Here lies the not-yet-implemented method 'Broadcast'
		// Here lies the not-yet-implemented method 'BroadcastTeam'
		// Here lies the not-yet-implemented method 'AllowBroadcastLocalized'
		// Here lies the not-yet-implemented method 'AllowBroadcastLocalizedTeam'
	};
}
#undef ADD_VAR
