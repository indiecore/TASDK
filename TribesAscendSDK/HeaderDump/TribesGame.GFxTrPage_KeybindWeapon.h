#pragma once
#include "TribesGame.GFxTrPage_KeybindAction.h"
namespace UnrealScript
{
	class GFxTrPage_KeybindWeapon : public GFxTrPage_KeybindAction
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_KeybindWeapon.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
