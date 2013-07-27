#pragma once
#include "TribesGame.GFxTrPage.h"
#include "TribesGame.GFxTrAction.h"
namespace UnrealScript
{
	class GFxTrPage_RoamCTF : public GFxTrPage
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60467);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60468);
			byte params[4] = { NULL };
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JoinLocalGame(ScriptString* SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60470);
			byte params[12] = { NULL };
			*(ScriptString**)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowModel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60472);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
