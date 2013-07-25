#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTLocalMessage.h"
#include "Engine__SoundNodeWave.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSpinfusorSpreeMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrSpinfusorSpreeMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrSpinfusorSpreeMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, EndSpreeNoteTrailer, 0xFFFFFFFF)
		ADD_OBJECT(SoundNodeWave, SpreeSound)
		ADD_VAR(::StrProperty, SelfSpreeNote, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SpreeNote, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MultiKillString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EndSelfSpree, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EndSpreeNote, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetFontSize'
		// Here lies the not-yet-implemented method 'GetString'
		// Here lies the not-yet-implemented method 'ClientReceive'
		// Here lies the not-yet-implemented method 'AnnouncementSound'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
