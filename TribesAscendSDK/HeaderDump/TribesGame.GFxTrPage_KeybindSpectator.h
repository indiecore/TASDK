#pragma once
#include "TribesGame.GFxTrPage.h"
namespace UnrealScript
{
	class GFxTrPage_KeybindSpectator : public GFxTrPage
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59330);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
