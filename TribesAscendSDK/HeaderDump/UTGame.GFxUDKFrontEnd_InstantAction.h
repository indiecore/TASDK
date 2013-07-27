#pragma once
#include "UTGame.GFxUDKFrontEnd_LaunchGame.h"
namespace UnrealScript
{
	class GFxUDKFrontEnd_InstantAction : public GFxUDKFrontEnd_LaunchGame
	{
	public:
		void OnViewActivated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38365);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnStartGame_Confirm()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38366);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
