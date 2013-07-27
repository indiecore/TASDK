#pragma once
#include "UTGame.GFxUDKFrontEnd_LaunchGame.h"
namespace UnrealScript
{
	class GFxUDKFrontEnd_HostGame : public GFxUDKFrontEnd_LaunchGame
	{
	public:
		static const auto SERVERTYPE_LAN = 0;
		static const auto SERVERTYPE_UNRANKED = 1;
		static const auto SERVERTYPE_RANKED = 2;
		static const auto MAXIMUM_PLAYER_COUNT = 24;
		void OnViewActivated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.OnViewActivated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.OnTopMostView");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* StripInvalidPasswordCharacters(ScriptString* PasswordString, ScriptString* InvalidChars)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.StripInvalidPasswordCharacters");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = PasswordString;
			*(ScriptString**)&params[12] = InvalidChars;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[24];
		}
		void ValidateServerType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.ValidateServerType");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GenerateMutatorURLString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.GenerateMutatorURLString");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void SetupGameSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.SetupGameSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateOnlineGame(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.CreateOnlineGame");
			byte params[4] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameCreated(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_HostGame.OnGameCreated");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
