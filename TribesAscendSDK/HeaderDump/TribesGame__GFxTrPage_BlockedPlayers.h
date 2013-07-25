#pragma once
#include "TribesGame__GFxTrPage.h"
#include "GFxUI__GFxObject.h"
#include "TribesGame__GFxTrAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_BlockedPlayers." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_BlockedPlayers : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, FlyoutTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, UnblockOption, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BlockedStatus, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BlockSubtext, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BlockOption, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForFriendRemovePopup, 0x2)
		ADD_VAR(::BoolProperty, bWaitingForFriendAddPopup, 0x1)
		ADD_VAR(::IntProperty, RemovingIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevPlayerId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FocusedIndex, 0xFFFFFFFF)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_BlockedPlayers.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_BlockedPlayers.FillData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_BlockedPlayers.SpecialAction");
			byte* params = (byte*)malloc(4);
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckPricing(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_BlockedPlayers.CheckPricing");
			byte* params = (byte*)malloc(8);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class GFxObject* FillPricing(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_BlockedPlayers.FillPricing");
			byte* params = (byte*)malloc(8);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 4);
			free(params);
			return returnVal;
		}
		void ModifyFocus(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_BlockedPlayers.ModifyFocus");
			byte* params = (byte*)malloc(4);
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int ModifyAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_BlockedPlayers.ModifyAction");
			byte* params = (byte*)malloc(12);
			*(int*)params = ActionIndex;
			*(class GFxObject**)(params + 4) = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void RefreshButtons()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_BlockedPlayers.RefreshButtons");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int TakeFocus(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_BlockedPlayers.TakeFocus");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_BlockedPlayers.FillOption");
			byte* params = (byte*)malloc(8);
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 4);
			free(params);
			return returnVal;
		}
		int FindNextBlocked()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_BlockedPlayers.FindNextBlocked");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void PopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_BlockedPlayers.PopupData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PopupComplete(int Action, ScriptArray<wchar_t> TextInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_BlockedPlayers.PopupComplete");
			byte* params = (byte*)malloc(16);
			*(int*)params = Action;
			*(ScriptArray<wchar_t>*)(params + 4) = TextInput;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
