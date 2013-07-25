#pragma once
#include "UTGame.UTTeamGame.h"
namespace UnrealScript
{
	class UTEntryGame : public UTTeamGame
	{
	public:
		bool NeedPlayers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTEntryGame.NeedPlayers");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void StartMatch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTEntryGame.StartMatch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitGame(ScriptArray<wchar_t> Options, ScriptArray<wchar_t>& ErrorMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTEntryGame.InitGame");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Options;
			*(ScriptArray<wchar_t>*)(params + 12) = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ErrorMessage = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
		}
	};
}
