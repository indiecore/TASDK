#pragma once
#include "GFxUI__GFxObject.h"
#include "TribesGame__GFxTrAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage : public GFxObject
	{
	public:
		ADD_VAR(::StrProperty, HelpButtonYLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpButtonXLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpButtonBLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpButtonALabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpButtonYKey, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpButtonXKey, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpButtonBKey, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpButtonAKey, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PageLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PageLabelOverride, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowTribesLogo, 0x200)
		ADD_VAR(::BoolProperty, bParentLocked, 0x100)
		ADD_VAR(::BoolProperty, bHasModifiers, 0x80)
		ADD_VAR(::BoolProperty, bCreated, 0x40)
		ADD_VAR(::BoolProperty, bActive, 0x20)
		ADD_VAR(::BoolProperty, bAllowBack, 0x10)
		ADD_VAR(::BoolProperty, bEndOfLine, 0x8)
		ADD_VAR(::BoolProperty, bRemoveOption, 0x4)
		ADD_VAR(::BoolProperty, bModifyOption, 0x2)
		ADD_VAR(::BoolProperty, bFillingFocus, 0x1)
		ADD_VAR(::IntProperty, LoadoutEquipType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LoadoutClassId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NewAction, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OptionCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DataCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ActiveIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ScrollIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HelpButtonYNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HelpButtonXNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HelpButtonBNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HelpButtonANum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GoBack, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ActiveLoadout, 0xFFFFFFFF)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class GFxTrAction* AddAction()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.AddAction");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxTrAction**)params;
			free(params);
			return returnVal;
		}
		class GFxTrAction* AddActionNumber(int ActionNumber)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.AddActionNumber");
			byte* params = (byte*)malloc(8);
			*(int*)params = ActionNumber;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxTrAction**)(params + 4);
			free(params);
			return returnVal;
		}
		class GFxTrAction* AddActionString(ScriptArray<wchar_t> ActionString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.AddActionString");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = ActionString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxTrAction**)(params + 12);
			free(params);
			return returnVal;
		}
		class GFxTrAction* AddActionPage(class GFxTrPage* ActionPage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.AddActionPage");
			byte* params = (byte*)malloc(8);
			*(class GFxTrPage**)params = ActionPage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxTrAction**)(params + 4);
			free(params);
			return returnVal;
		}
		class GFxTrAction* AddActionSet(class GFxTrPage* ActionPage, int ActionNumber, ScriptArray<wchar_t> ActionString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.AddActionSet");
			byte* params = (byte*)malloc(24);
			*(class GFxTrPage**)params = ActionPage;
			*(int*)(params + 4) = ActionNumber;
			*(ScriptArray<wchar_t>*)(params + 8) = ActionString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxTrAction**)(params + 20);
			free(params);
			return returnVal;
		}
		int TakeFocus(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.TakeFocus");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.TakeAction");
			byte* params = (byte*)malloc(12);
			*(int*)params = ActionIndex;
			*(class GFxObject**)(params + 4) = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int ModifyAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.ModifyAction");
			byte* params = (byte*)malloc(12);
			*(int*)params = ActionIndex;
			*(class GFxObject**)(params + 4) = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void ModifyFocus(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.ModifyFocus");
			byte* params = (byte*)malloc(4);
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HelpButton(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.HelpButton");
			byte* params = (byte*)malloc(4);
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.SpecialAction");
			byte* params = (byte*)malloc(4);
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.PopupData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PopupComplete(int Action, ScriptArray<wchar_t> TextInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.PopupComplete");
			byte* params = (byte*)malloc(16);
			*(int*)params = Action;
			*(ScriptArray<wchar_t>*)(params + 4) = TextInput;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxObject* FillOptions(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillOptions");
			byte* params = (byte*)malloc(8);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsOwned(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.IsOwned");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckPurchasable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.CheckPurchasable");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsEquipMaxed(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.IsEquipMaxed");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillOption");
			byte* params = (byte*)malloc(8);
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 4);
			free(params);
			return returnVal;
		}
		class GFxObject* FillDefault()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillDefault");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)params;
			free(params);
			return returnVal;
		}
		bool CheckUpgrades(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.CheckUpgrades");
			byte* params = (byte*)malloc(8);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckPricing(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.CheckPricing");
			byte* params = (byte*)malloc(8);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class GFxObject* FillUpgrades(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillUpgrades");
			byte* params = (byte*)malloc(8);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 4);
			free(params);
			return returnVal;
		}
		class GFxObject* FillPricing(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillPricing");
			byte* params = (byte*)malloc(8);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 4);
			free(params);
			return returnVal;
		}
		void CheckDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.CheckDescription");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxObject* FillDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillDescription");
			byte* params = (byte*)malloc(8);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 4);
			free(params);
			return returnVal;
		}
		void FillPage(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillPage");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearActions()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.ClearActions");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowModel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.ShowModel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class GFxObject* FillClass(int ClassId, int ActionIndex, bool bShowActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillClass");
			byte* params = (byte*)malloc(16);
			*(int*)params = ClassId;
			*(int*)(params + 4) = ActionIndex;
			*(bool*)(params + 8) = bShowActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 12);
			free(params);
			return returnVal;
		}
		class GFxObject* FillEquipTypes(int EquipId, int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillEquipTypes");
			byte* params = (byte*)malloc(12);
			*(int*)params = EquipId;
			*(int*)(params + 4) = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 8);
			free(params);
			return returnVal;
		}
		bool NewClassEquip(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.NewClassEquip");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NewClassUpgrade(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.NewClassUpgrade");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NewEquipUpgrade(int EquipId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.NewEquipUpgrade");
			byte* params = (byte*)malloc(8);
			*(int*)params = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void RevertSetting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.RevertSetting");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPurchaseSuccess()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.OnPurchaseSuccess");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ActionUp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.ActionUp");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ActionDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.ActionDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshButtons()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.RefreshButtons");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KeyEvent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.KeyEvent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateDealTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.UpdateDealTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateQueueTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.UpdateQueueTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProfileUp(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.ProfileUp");
			byte* params = (byte*)malloc(4);
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProfileDown(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.ProfileDown");
			byte* params = (byte*)malloc(4);
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetRunaway()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.ResetRunaway");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowReticule(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.ShowReticule");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SaveReticule(class GFxObject* Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.SaveReticule");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnClose()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.OnClose");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
