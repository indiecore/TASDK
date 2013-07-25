#pragma once
#include "UTGame.GFxUDKFrontEnd_LaunchGame.h"
namespace UnrealScript
{
	class GFxUDKFrontEnd_InstantAction : public GFxUDKFrontEnd_LaunchGame
	{
	public:
		void OnViewActivated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InstantAction.OnViewActivated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnStartGame_Confirm()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InstantAction.OnStartGame_Confirm");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
