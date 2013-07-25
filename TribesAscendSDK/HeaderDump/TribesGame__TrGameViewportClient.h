#pragma once
#include "UTGame__UTGameViewportClient.h"
#include "Engine__Canvas.h"
#include "TribesGame__TrChatConsole.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGameViewportClient." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGameViewportClient : public UTGameViewportClient
	{
	public:
		ADD_OBJECT(TrChatConsole, ChatConsole)
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'PostRender'
	};
}
#undef ADD_OBJECT
