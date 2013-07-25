#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
namespace UnrealScript
{
	class GFxTrPage_RoamTDM : public GFxTrPage
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_RoamTDM.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_RoamTDM.SpecialAction");
			byte* params = (byte*)malloc(4);
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void JoinLocalGame(ScriptArray<wchar_t> SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_RoamTDM.JoinLocalGame");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowModel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_RoamTDM.ShowModel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
