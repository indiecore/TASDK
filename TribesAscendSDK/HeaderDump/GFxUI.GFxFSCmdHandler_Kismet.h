#pragma once
#include "GFxUI.GFxFSCmdHandler.h"
#include "GFxUI.GFxEvent_FSCommand.h"
#include "GFxUI.GFxMoviePlayer.h"
namespace UnrealScript
{
	class GFxFSCmdHandler_Kismet : public GFxFSCmdHandler
	{
	public:
		bool FSCommand(class GFxMoviePlayer* Movie, class GFxEvent_FSCommand* Event, ScriptString* Cmd, ScriptString* Arg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30296);
			byte params[36] = { NULL };
			*(class GFxMoviePlayer**)params = Movie;
			*(class GFxEvent_FSCommand**)&params[4] = Event;
			*(ScriptString**)&params[8] = Cmd;
			*(ScriptString**)&params[20] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
	};
}
