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
		bool Init(ScriptArray<wchar_t>& OutError)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameViewportClient.Init");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = OutError;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutError = *(ScriptArray<wchar_t>*)params;
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void PostRender(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameViewportClient.PostRender");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
