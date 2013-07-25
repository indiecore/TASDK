#pragma once
#include "TribesGame__GFxTrPage_KeybindAction.h"
namespace UnrealScript
{
	class GFxTrPage_KeybindVehicle : public GFxTrPage_KeybindAction
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_KeybindVehicle.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
