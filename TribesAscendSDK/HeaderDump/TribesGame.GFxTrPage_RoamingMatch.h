#pragma once
#include "TribesGame.GFxTrPage.h"
namespace UnrealScript
{
	class GFxTrPage_RoamingMatch : public GFxTrPage
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60476);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowModel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60481);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
