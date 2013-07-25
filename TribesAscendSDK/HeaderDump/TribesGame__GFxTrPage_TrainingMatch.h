#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
#include "GFxUI__GFxObject.h"
namespace UnrealScript
{
	class GFxTrPage_TrainingMatch : public GFxTrPage
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_TrainingMatch.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_TrainingMatch.SpecialAction");
			byte* params = (byte*)malloc(4);
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void JoinLocalGame(ScriptArray<wchar_t> SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_TrainingMatch.JoinLocalGame");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int TakeFocus(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_TrainingMatch.TakeFocus");
			byte* params = (byte*)malloc(12);
			*(int*)params = ActionIndex;
			*(class GFxObject**)(params + 4) = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_TrainingMatch.FillOption");
			byte* params = (byte*)malloc(8);
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
