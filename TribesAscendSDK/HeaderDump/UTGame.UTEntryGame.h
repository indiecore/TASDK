#pragma once
#include "UTGame.UTTeamGame.h"
namespace UnrealScript
{
	class UTEntryGame : public UTTeamGame
	{
	public:
		bool NeedPlayers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47395);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void StartMatch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47397);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitGame(ScriptString* Options, ScriptString*& ErrorMessage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47398);
			byte params[24] = { NULL };
			*(ScriptString**)params = Options;
			*(ScriptString**)&params[12] = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ErrorMessage = *(ScriptString**)&params[12];
		}
	};
}
