#pragma once
#include "Engine.HUD.h"
namespace UnrealScript
{
	class UTEntryHUD : public HUD
	{
	public:
		void PostRender()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47410);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
