#pragma once
#include "Core.Object.h"
#include "GFxUI.GFxEvent_FSCommand.h"
#include "GFxUI.GFxMoviePlayer.h"
namespace UnrealScript
{
	class GFxFSCmdHandler : public Object
	{
	public:
		bool FSCommand(class GFxMoviePlayer* Movie, class GFxEvent_FSCommand* Event, ScriptString* Cmd, ScriptString* Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxFSCmdHandler.FSCommand");
			byte params[36] = { NULL };
			*(class GFxMoviePlayer**)&params[0] = Movie;
			*(class GFxEvent_FSCommand**)&params[4] = Event;
			*(ScriptString**)&params[8] = Cmd;
			*(ScriptString**)&params[20] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
	};
}
