#pragma once
#include "TribesGame__GFxTrPage.h"
namespace UnrealScript
{
	class GFxTrPage_KeybindSpectator : public GFxTrPage
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_KeybindSpectator.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
