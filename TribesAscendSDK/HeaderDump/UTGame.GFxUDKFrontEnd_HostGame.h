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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38293);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38295);
			byte params[4] = { NULL };
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* StripInvalidPasswordCharacters(ScriptString* PasswordString, ScriptString* InvalidChars)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38297);
			byte params[36] = { NULL };
			*(ScriptString**)params = PasswordString;
			*(ScriptString**)&params[12] = InvalidChars;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[24];
		}
		void ValidateServerType()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38302);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GenerateMutatorURLString()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38307);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void SetupGameSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38315);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateOnlineGame(int PlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38324);
			byte params[4] = { NULL };
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameCreated(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38328);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FinishStartDedicated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38340);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnStartGame_Confirm()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38346);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
