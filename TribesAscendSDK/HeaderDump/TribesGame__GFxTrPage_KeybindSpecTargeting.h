#pragma once
#include "TribesGame__GFxTrPage_KeybindAction.h"
namespace UnrealScript
{
	class GFxTrPage_KeybindSpecTargeting : public GFxTrPage_KeybindAction
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_KeybindSpecTargeting.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
