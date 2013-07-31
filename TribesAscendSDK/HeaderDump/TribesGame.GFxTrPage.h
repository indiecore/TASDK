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
		struct ResolutionSet
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56697);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class GFxTrAction* AddAction()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56698);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxTrAction**)params;
		}
		class GFxTrAction* AddActionNumber(int ActionNumber)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56701);
			byte params[8] = { NULL };
			*(int*)params = ActionNumber;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxTrAction**)&params[4];
		}
		class GFxTrAction* AddActionString(ScriptString* ActionString)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56705);
			byte params[16] = { NULL };
			*(ScriptString**)params = ActionString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxTrAction**)&params[12];
		}
		class GFxTrAction* AddActionPage(class GFxTrPage* ActionPage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56709);
			byte params[8] = { NULL };
			*(class GFxTrPage**)params = ActionPage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxTrAction**)&params[4];
		}
		class GFxTrAction* AddActionSet(class GFxTrPage* ActionPage, int ActionNumber, ScriptString* ActionString)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56713);
			byte params[24] = { NULL };
			*(class GFxTrPage**)params = ActionPage;
			*(int*)&params[4] = ActionNumber;
			*(ScriptString**)&params[8] = ActionString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxTrAction**)&params[20];
		}
		int TakeFocus(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56719);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int TakeAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56724);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int ModifyAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56730);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void ModifyFocus(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56734);
			byte params[4] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HelpButton(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56736);
			byte params[4] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56741);
			byte params[4] = { NULL };
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56743);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopupComplete(int Action, ScriptString* TextInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56745);
			byte params[16] = { NULL };
			*(int*)params = Action;
			*(ScriptString**)&params[4] = TextInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56748);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillOptions(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56752);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		bool IsOwned(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56758);
			byte params[8] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckPurchasable()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56761);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsEquipMaxed(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56763);
			byte params[8] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56766);
			byte params[8] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		class GFxObject* FillDefault()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56770);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)params;
		}
		bool CheckUpgrades(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56773);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckPricing(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56776);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class GFxObject* FillUpgrades(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56779);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		class GFxObject* FillPricing(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56782);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		void CheckDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56785);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56789);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		void FillPage(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56792);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearActions()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56794);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowModel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56796);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class GFxObject* FillClass(int ClassId, int ActionIndex, bool bShowActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56797);
			byte params[16] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = ActionIndex;
			*(bool*)&params[8] = bShowActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[12];
		}
		class GFxObject* FillEquipTypes(int EquipId, int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56844);
			byte params[12] = { NULL };
			*(int*)params = EquipId;
			*(int*)&params[4] = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[8];
		}
		bool NewClassEquip(int ClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56855);
			byte params[8] = { NULL };
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NewClassUpgrade(int ClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56858);
			byte params[8] = { NULL };
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NewEquipUpgrade(int EquipId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56861);
			byte params[8] = { NULL };
			*(int*)params = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void RevertSetting()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56864);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPurchaseSuccess()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56865);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ActionUp()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56866);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ActionDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56867);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshButtons()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56868);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KeyEvent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56872);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateDealTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56873);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateQueueTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56874);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProfileUp(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56875);
			byte params[4] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProfileDown(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56877);
			byte params[4] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetRunaway()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56879);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowReticule(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56881);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveReticule(class GFxObject* Data)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56883);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnClose()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56885);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
