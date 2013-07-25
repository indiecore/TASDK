#pragma once
#include "UTGame__UTConsole.h"
#include "TribesGame__TrPlayerController.h"
#include "Engine__Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrChatConsole." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrChatConsole." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrChatConsole : public UTConsole
	{
	public:
		ADD_OBJECT(TrPlayerController, m_TrPC)
		ADD_VAR(::FloatProperty, m_fTypingTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EscHelp, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TabHelp, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TellHelp, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SlashHelp, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastFriendCount, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ChannelStr, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialized'
		// Here lies the not-yet-implemented method 'GetPlayerController'
		// Here lies the not-yet-implemented method 'ConsoleCommand'
		// Here lies the not-yet-implemented method 'StartTypingChat'
		// Here lies the not-yet-implemented method 'StartTyping'
		// Here lies the not-yet-implemented method 'IsSlashCommand'
		// Here lies the not-yet-implemented method 'IsPlayerTell'
		// Here lies the not-yet-implemented method 'PostRender_Console'
		// Here lies the not-yet-implemented method 'InputKey'
		// Here lies the not-yet-implemented method 'AddOnlineFriendHelp'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
