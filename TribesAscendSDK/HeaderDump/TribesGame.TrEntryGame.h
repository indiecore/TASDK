#pragma once
#include "UTGame.UTEntryGame.h"
namespace UnrealScript
{
	class TrEntryGame : public UTEntryGame
	{
	public:
		void SendMenuEngineLoaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryGame.SendMenuEngineLoaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptClass* SetGameType(ScriptString* MapName, ScriptString* Options, ScriptString* Portal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryGame.SetGameType");
			byte params[40] = { NULL };
			*(ScriptString**)&params[0] = MapName;
			*(ScriptString**)&params[12] = Options;
			*(ScriptString**)&params[24] = Portal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[36];
		}
		void OnEngineHasLoaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryGame.OnEngineHasLoaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
