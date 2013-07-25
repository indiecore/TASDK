#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_TrainVideo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_TrainVideo : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bValid, 0x1)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_TrainVideo.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowModel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_TrainVideo.ShowModel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_TrainVideo.SpecialAction");
			byte* params = (byte*)malloc(4);
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_TrainVideo.FillData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_TrainVideo.FillOption");
			byte* params = (byte*)malloc(8);
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 4);
			free(params);
			return returnVal;
		}
		class GFxObject* FillDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_TrainVideo.FillDescription");
			byte* params = (byte*)malloc(8);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
