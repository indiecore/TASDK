#pragma once
#include "TribesGame__GFxTrPage.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_CustomMatch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_CustomMatch : public GFxTrPage
	{
	public:
		ADD_VAR(::IntProperty, SERVERS_PER_PAGE, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, QueueJoinName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PopupNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ServerIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForJoinPopup, 0x10)
		ADD_VAR(::BoolProperty, bFilterPopup, 0x8)
		ADD_VAR(::BoolProperty, bRefresh, 0x4)
		ADD_VAR(::BoolProperty, bFilterEmpty, 0x2)
		ADD_VAR(::BoolProperty, bFilterFull, 0x1)
		ADD_VAR(::StrProperty, ServerNameFilter, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MapNameFilter, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FilterServerNameNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FilterOwnerNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FilterFullNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FilterEmptyNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FilterMapNameNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FilterRegionNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RefreshNum, 0xFFFFFFFF)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_CustomMatch.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_CustomMatch.FillData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int TakeFocus(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_CustomMatch.TakeFocus");
			byte* params = (byte*)malloc(12);
			*(int*)params = ActionIndex;
			*(class GFxObject**)(params + 4) = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int TakeAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_CustomMatch.TakeAction");
			byte* params = (byte*)malloc(12);
			*(int*)params = ActionIndex;
			*(class GFxObject**)(params + 4) = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void PopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_CustomMatch.PopupData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PopupComplete(int Action, ScriptArray<wchar_t> TextInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_CustomMatch.PopupComplete");
			byte* params = (byte*)malloc(16);
			*(int*)params = Action;
			*(ScriptArray<wchar_t>*)(params + 4) = TextInput;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxObject* FillServerBrowser()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_CustomMatch.FillServerBrowser");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)params;
			free(params);
			return returnVal;
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_CustomMatch.FillOption");
			byte* params = (byte*)malloc(8);
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 4);
			free(params);
			return returnVal;
		}
		void ActionUp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_CustomMatch.ActionUp");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ActionDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_CustomMatch.ActionDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> GetLevelReq(int Min, int Max)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_CustomMatch.GetLevelReq");
			byte* params = (byte*)malloc(20);
			*(int*)params = Min;
			*(int*)(params + 4) = Max;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 8);
			free(params);
			return returnVal;
		}
		void WaitPopup(ScriptArray<wchar_t> ServerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_CustomMatch.WaitPopup");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = ServerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowModel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_CustomMatch.ShowModel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
