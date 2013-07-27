#pragma once
#include "UTGame.UTGameViewportClient.h"
#include "TribesGame.TrChatConsole.h"
#include "Engine.Canvas.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrGameViewportClient : public UTGameViewportClient
	{
	public:
		ADD_OBJECT(TrChatConsole, ChatConsole, 408)
		bool Init(ScriptString*& OutError)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(95387);
			byte params[16] = { NULL };
			*(ScriptString**)params = OutError;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutError = *(ScriptString**)params;
			return *(bool*)&params[12];
		}
		void PostRender(class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(95390);
			byte params[4] = { NULL };
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
