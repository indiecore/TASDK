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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61499);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowModel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61500);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61502);
			byte params[4] = { NULL };
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateStreams()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61506);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61512);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61514);
			byte params[8] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		class GFxObject* FillDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61529);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		bool IsFeatured(int Num)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61535);
			byte params[8] = { NULL };
			*(int*)params = Num;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_STRUCT
