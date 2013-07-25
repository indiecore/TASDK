#pragma once
#include "UTGame__UTEntryGame.h"
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
		ScriptClass* SetGameType(ScriptArray<wchar_t> MapName, ScriptArray<wchar_t> Options, ScriptArray<wchar_t> Portal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryGame.SetGameType");
			byte* params = (byte*)malloc(40);
			*(ScriptArray<wchar_t>*)params = MapName;
			*(ScriptArray<wchar_t>*)(params + 12) = Options;
			*(ScriptArray<wchar_t>*)(params + 24) = Portal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 36);
			free(params);
			return returnVal;
		}
		void OnEngineHasLoaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryGame.OnEngineHasLoaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
