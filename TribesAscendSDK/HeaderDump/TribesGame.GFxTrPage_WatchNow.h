#pragma once
#include "TribesGame.GFxTrPage.h"
#include "TribesGame.GFxTrAction.h"
#include "GFxUI.GFxObject.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_WatchNow : public GFxTrPage
	{
	public:
		ADD_STRUCT(ScriptArray<int>, FeaturedNums, 420)
		ADD_STRUCT(ScriptString*, strCmntyVideos, 408)
		ADD_STRUCT(ScriptString*, strTrainVideos, 396)
		ADD_STRUCT(ScriptString*, strHiRezVideos, 384)
		ADD_STRUCT(ScriptString*, strLiveStreams, 372)
		ADD_STRUCT(int, NumCmntyVideos, 368)
		ADD_STRUCT(int, NumTrainVideos, 364)
		ADD_STRUCT(int, NumHiRezVideos, 360)
		ADD_STRUCT(int, NumLiveStreams, 356)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_WatchNow.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowModel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_WatchNow.ShowModel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_WatchNow.SpecialAction");
			byte params[4] = { NULL };
			*(class GFxTrAction**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateStreams()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_WatchNow.UpdateStreams");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_WatchNow.FillData");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_WatchNow.FillOption");
			byte params[8] = { NULL };
			*(int*)&params[0] = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		class GFxObject* FillDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_WatchNow.FillDescription");
			byte params[8] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		bool IsFeatured(int Num)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_WatchNow.IsFeatured");
			byte params[8] = { NULL };
			*(int*)&params[0] = Num;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_STRUCT
