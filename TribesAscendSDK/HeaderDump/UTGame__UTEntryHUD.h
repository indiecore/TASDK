#pragma once
#include "Engine__HUD.h"
namespace UnrealScript
{
	class UTEntryHUD : public HUD
	{
	public:
		void PostRender()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTEntryHUD.PostRender");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
