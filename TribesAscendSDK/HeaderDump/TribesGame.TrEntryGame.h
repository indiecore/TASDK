#pragma once
#include "UTGame.UTEntryGame.h"
namespace UnrealScript
{
	class TrEntryGame : public UTEntryGame
	{
	public:
		void SendMenuEngineLoaded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87278);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptClass* SetGameType(ScriptString* MapName, ScriptString* Options, ScriptString* Portal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87279);
			byte params[40] = { NULL };
			*(ScriptString**)params = MapName;
			*(ScriptString**)&params[12] = Options;
			*(ScriptString**)&params[24] = Portal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[36];
		}
		void OnEngineHasLoaded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87284);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
