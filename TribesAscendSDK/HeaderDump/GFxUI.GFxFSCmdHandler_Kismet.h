#pragma once
#include "GFxUI.GFxFSCmdHandler.h"
#include "GFxUI.GFxEvent_FSCommand.h"
#include "GFxUI.GFxMoviePlayer.h"
namespace UnrealScript
{
	class GFxFSCmdHandler_Kismet : public GFxFSCmdHandler
	{
	public:
		bool FSCommand(class GFxMoviePlayer* Movie, class GFxEvent_FSCommand* Event, ScriptArray<wchar_t> Cmd, ScriptArray<wchar_t> Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxFSCmdHandler_Kismet.FSCommand");
			byte* params = (byte*)malloc(36);
			*(class GFxMoviePlayer**)params = Movie;
			*(class GFxEvent_FSCommand**)(params + 4) = Event;
			*(ScriptArray<wchar_t>*)(params + 8) = Cmd;
			*(ScriptArray<wchar_t>*)(params + 20) = Arg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
	};
}
