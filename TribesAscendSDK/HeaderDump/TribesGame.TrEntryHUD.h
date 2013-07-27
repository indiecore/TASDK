#pragma once
#include "Engine.HUD.h"
namespace UnrealScript
{
	class TrEntryHUD : public HUD
	{
	public:
		void CreateMainMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87285);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87286);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
