#pragma once
#include "UTGame.GFxUDKFrontEnd_LaunchGame.h"
namespace UnrealScript
{
	class GFxUDKFrontEnd_HostGame : public GFxUDKFrontEnd_LaunchGame
	{
	public:
		void OnViewActivated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.OnViewActivated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.OnTopMostView");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> StripInvalidPasswordCharacters(ScriptArray<wchar_t> PasswordString, ScriptArray<wchar_t> InvalidChars)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.StripInvalidPasswordCharacters");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = PasswordString;
			*(ScriptArray<wchar_t>*)(params + 12) = InvalidChars;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 24);
			free(params);
			return returnVal;
		}
		void ValidateServerType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.ValidateServerType");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> GenerateMutatorURLString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.GenerateMutatorURLString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void SetupGameSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.SetupGameSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateOnlineGame(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.CreateOnlineGame");
			byte* params = (byte*)malloc(4);
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnGameCreated(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.OnGameCreated");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FinishStartDedicated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.FinishStartDedicated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnStartGame_Confirm()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.OnStartGame_Confirm");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
