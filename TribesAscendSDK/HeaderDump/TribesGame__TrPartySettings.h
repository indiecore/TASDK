#pragma once
#include "Engine__OnlineSubsystem.h"
#include "Engine__OnlineGameSettings.h"
#include "Engine__LocalPlayer.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPartySettings." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPartySettings : public OnlineGameSettings
	{
	public:
		ADD_OBJECT(OnlineSubsystem, OnlineSub)
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'Close'
		// Here lies the not-yet-implemented method 'OnLoginChange'
		// Here lies the not-yet-implemented method 'RefreshMembersList'
	};
}
#undef ADD_OBJECT
