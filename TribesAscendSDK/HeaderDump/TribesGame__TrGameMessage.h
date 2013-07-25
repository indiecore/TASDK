#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGameMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGameMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGameMessage : public UTLocalMessage
	{
	public:
		ADD_OBJECT(SoundCue, m_sMatchStartDiamondSword)
		ADD_OBJECT(SoundCue, m_sMatchStartBloodEagle)
		ADD_VAR(::StrProperty, WaitingForPlayers, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OvertimeNotification, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouAreOnDiamondSwordMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouAreOnBloodEagleMessage, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetString'
		// Here lies the not-yet-implemented method 'ClientReceive'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
