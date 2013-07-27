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
	class GFxTrPage_PlayNow : public GFxTrPage
	{
	public:
		static const auto QUI_CTF = 10350;
		static const auto QUI_TeamRabbit = 10351;
		static const auto QUI_Arena = 10352;
		static const auto QUI_Rabbit = 10353;
		static const auto QUI_Special = 10354;
		static const auto QUI_CaptureAndHold = 10377;
		ADD_STRUCT(ScriptString*, SeasonUpcomingSubtext, 476)
		ADD_STRUCT(ScriptString*, NoFriendsOnlineLabel, 464)
		ADD_STRUCT(ScriptString*, RegionsSubtext, 452)
		ADD_STRUCT(ScriptString*, RegionsLabel, 440)
		ADD_STRUCT(ScriptString*, RankedLabel, 428)
		ADD_STRUCT(ScriptString*, CustomServerLabel, 416)
		ADD_STRUCT(ScriptString*, JoinFriendLabel, 404)
		ADD_STRUCT(ScriptString*, JoinFriendInGameSubLabel, 392)
		ADD_STRUCT(ScriptString*, JoinFriendSubLabel, 380)
		ADD_STRUCT(ScriptString*, CustomServerSubtext, 368)
		ADD_STRUCT(ScriptString*, ComingSoonSubtext, 356)
		int GetMeshEnumFromVV(int InVal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_PlayNow.GetMeshEnumFromVV");
			byte params[8] = { NULL };
			*(int*)&params[0] = InVal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_PlayNow.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_PlayNow.SpecialAction");
			byte params[4] = { NULL };
			*(class GFxTrAction**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int TakeAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_PlayNow.TakeAction");
			byte params[12] = { NULL };
			*(int*)&params[0] = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void RefreshButtons()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_PlayNow.RefreshButtons");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_PlayNow.FillData");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveDuplicateQueues()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_PlayNow.RemoveDuplicateQueues");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool HaveDuplicates(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_PlayNow.HaveDuplicates");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_PlayNow.FillOption");
			byte params[8] = { NULL };
			*(int*)&params[0] = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		int TakeFocus(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_PlayNow.TakeFocus");
			byte params[12] = { NULL };
			*(int*)&params[0] = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
	};
}
#undef ADD_STRUCT
