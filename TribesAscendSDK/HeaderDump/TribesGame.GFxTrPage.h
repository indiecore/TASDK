#pragma once
#include "GFxUI.GFxObject.h"
#include "TribesGame.GFxTrAction.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage : public GFxObject
	{
	public:
		static const auto MENU_ELEMENT_LOGIN = 1;
		static const auto MENU_ELEMENT_OPTIONS = 2;
		static const auto MENU_ELEMENT_SIDEBAR = 3;
		static const auto MENU_ELEMENT_DESCRIPTION = 4;
		static const auto MENU_ELEMENT_UPGRADES = 5;
		static const auto MENU_ELEMENT_POPUPACQ = 6;
		static const auto MENU_ELEMENT_POPUPALERT = 7;
		static const auto MENU_ELEMENT_POPUPPURCHASE = 8;
		static const auto MENU_ELEMENT_SUMMARYPLAYER = 9;
		static const auto MENU_ELEMENT_SUMMARYTEAM = 10;
		static const auto MENU_ELEMENT_NOUSE = 11;
		static const auto MENU_ELEMENT_PRICE = 12;
		static const auto MENU_ELEMENT_PROFILE = 13;
		static const auto MENU_ELEMENT_FEATURE = 14;
		static const auto MENU_ELEMENT_SERVERBROWSER = 15;
		static const auto MAX_FRIENDS_DISPLAYED = 150;
		class ResolutionSet
		{
		public:
			ADD_STRUCT(TgPlayerProfile::PropertyPair, Res, 4)
			ADD_STRUCT(int, Index, 0)
		};
		ADD_STRUCT(ScriptArray<ScriptString*>, OptionTitlesOverride, 188)
		ADD_STRUCT(ScriptArray<ScriptString*>, OptionSubtextOverride, 200)
		ADD_STRUCT(ScriptArray<ScriptString*>, OptionTitles, 320)
		ADD_STRUCT(ScriptArray<ScriptString*>, OptionSubtext, 332)
		ADD_STRUCT(ScriptArray<class GFxTrAction*>, PageActions, 344)
		ADD_STRUCT(ScriptString*, HelpButtonYLabel, 308)
		ADD_STRUCT(ScriptString*, HelpButtonXLabel, 296)
		ADD_STRUCT(ScriptString*, HelpButtonBLabel, 284)
		ADD_STRUCT(ScriptString*, HelpButtonALabel, 272)
		ADD_STRUCT(ScriptString*, HelpButtonYKey, 260)
		ADD_STRUCT(ScriptString*, HelpButtonXKey, 248)
		ADD_STRUCT(ScriptString*, HelpButtonBKey, 236)
		ADD_STRUCT(ScriptString*, HelpButtonAKey, 224)
		ADD_STRUCT(ScriptString*, PageLabel, 212)
		ADD_STRUCT(ScriptString*, PageLabelOverride, 176)
		ADD_BOOL(bShowTribesLogo, 172, 0x200)
		ADD_BOOL(bParentLocked, 172, 0x100)
		ADD_BOOL(bHasModifiers, 172, 0x80)
		ADD_BOOL(bCreated, 172, 0x40)
		ADD_BOOL(bActive, 172, 0x20)
		ADD_BOOL(bAllowBack, 172, 0x10)
		ADD_BOOL(bEndOfLine, 172, 0x8)
		ADD_BOOL(bRemoveOption, 172, 0x4)
		ADD_BOOL(bModifyOption, 172, 0x2)
		ADD_BOOL(bFillingFocus, 172, 0x1)
		ADD_STRUCT(int, LoadoutEquipType, 168)
		ADD_STRUCT(int, LoadoutClassId, 164)
		ADD_STRUCT(int, NewAction, 160)
		ADD_STRUCT(int, OptionCount, 156)
		ADD_STRUCT(int, DataCount, 152)
		ADD_STRUCT(int, ActiveIndex, 148)
		ADD_STRUCT(int, ScrollIndex, 144)
		ADD_STRUCT(int, HelpButtonYNum, 140)
		ADD_STRUCT(int, HelpButtonXNum, 136)
		ADD_STRUCT(int, HelpButtonBNum, 132)
		ADD_STRUCT(int, HelpButtonANum, 128)
		ADD_STRUCT(int, GoBack, 124)
		ADD_STRUCT(int, ActiveLoadout, 120)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class GFxTrAction* AddAction()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.AddAction");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxTrAction**)&params[0];
		}
		class GFxTrAction* AddActionNumber(int ActionNumber)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.AddActionNumber");
			byte params[8] = { NULL };
			*(int*)&params[0] = ActionNumber;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxTrAction**)&params[4];
		}
		class GFxTrAction* AddActionString(ScriptString* ActionString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.AddActionString");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = ActionString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxTrAction**)&params[12];
		}
		class GFxTrAction* AddActionPage(class GFxTrPage* ActionPage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.AddActionPage");
			byte params[8] = { NULL };
			*(class GFxTrPage**)&params[0] = ActionPage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxTrAction**)&params[4];
		}
		class GFxTrAction* AddActionSet(class GFxTrPage* ActionPage, int ActionNumber, ScriptString* ActionString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.AddActionSet");
			byte params[24] = { NULL };
			*(class GFxTrPage**)&params[0] = ActionPage;
			*(int*)&params[4] = ActionNumber;
			*(ScriptString**)&params[8] = ActionString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxTrAction**)&params[20];
		}
		int TakeFocus(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.TakeFocus");
			byte params[12] = { NULL };
			*(int*)&params[0] = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int TakeAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.TakeAction");
			byte params[12] = { NULL };
			*(int*)&params[0] = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int ModifyAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.ModifyAction");
			byte params[12] = { NULL };
			*(int*)&params[0] = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void ModifyFocus(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.ModifyFocus");
			byte params[4] = { NULL };
			*(int*)&params[0] = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HelpButton(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.HelpButton");
			byte params[4] = { NULL };
			*(int*)&params[0] = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.SpecialAction");
			byte params[4] = { NULL };
			*(class GFxTrAction**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.PopupData");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopupComplete(int Action, ScriptString* TextInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.PopupComplete");
			byte params[16] = { NULL };
			*(int*)&params[0] = Action;
			*(ScriptString**)&params[4] = TextInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillData");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillOptions(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillOptions");
			byte params[8] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		bool IsOwned(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.IsOwned");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckPurchasable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.CheckPurchasable");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsEquipMaxed(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.IsEquipMaxed");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillOption");
			byte params[8] = { NULL };
			*(int*)&params[0] = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		class GFxObject* FillDefault()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillDefault");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[0];
		}
		bool CheckUpgrades(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.CheckUpgrades");
			byte params[8] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckPricing(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.CheckPricing");
			byte params[8] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class GFxObject* FillUpgrades(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillUpgrades");
			byte params[8] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		class GFxObject* FillPricing(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillPricing");
			byte params[8] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		void CheckDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.CheckDescription");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillDescription");
			byte params[8] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		void FillPage(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillPage");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[16] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = ActionIndex;
			*(bool*)&params[8] = bShowActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[12];
		}
		class GFxObject* FillEquipTypes(int EquipId, int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.FillEquipTypes");
			byte params[12] = { NULL };
			*(int*)&params[0] = EquipId;
			*(int*)&params[4] = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[8];
		}
		bool NewClassEquip(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.NewClassEquip");
			byte params[8] = { NULL };
			*(int*)&params[0] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NewClassUpgrade(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.NewClassUpgrade");
			byte params[8] = { NULL };
			*(int*)&params[0] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NewEquipUpgrade(int EquipId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.NewEquipUpgrade");
			byte params[8] = { NULL };
			*(int*)&params[0] = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
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
			byte params[4] = { NULL };
			*(int*)&params[0] = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProfileDown(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.ProfileDown");
			byte params[4] = { NULL };
			*(int*)&params[0] = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetRunaway()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.ResetRunaway");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowReticule(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.ShowReticule");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveReticule(class GFxObject* Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.SaveReticule");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnClose()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage.OnClose");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
