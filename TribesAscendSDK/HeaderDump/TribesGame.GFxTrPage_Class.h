#pragma once
#include "TribesGame.GFxTrPage.h"
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
	class GFxTrPage_Class : public GFxTrPage
	{
	public:
		enum MENU_ACTION_CLASS : byte
		{
			MAC_PRIMARY = 0,
			MAC_SECONDARY = 1,
			MAC_BELT = 2,
			MAC_PACK = 3,
			MAC_ARMOR = 4,
			MAC_PERKA = 5,
			MAC_PERKB = 6,
			MAC_SKIN = 7,
			MAC_VOICE = 8,
			MAC_MAX = 9,
		};
		ADD_BOOL(bViewingEquip, 364, 0x2)
		ADD_BOOL(bClassLocked, 364, 0x1)
		ADD_STRUCT(int, NumRenameLoadout, 360)
		ADD_STRUCT(int, PopupNum, 356)
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58153);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58155);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58163);
			byte params[4] = { NULL };
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int TakeAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58171);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58175);
			byte params[8] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		int GetEquipType(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58183);
			byte params[8] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void CheckDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58186);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58190);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		ScriptString* GetArmorName(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58203);
			byte params[16] = { NULL };
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* GetEquipName(int equipType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58208);
			byte params[16] = { NULL };
			*(int*)params = equipType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void HelpButton(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58213);
			byte params[4] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58219);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopupComplete(int Action, ScriptString* TextInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58221);
			byte params[16] = { NULL };
			*(int*)params = Action;
			*(ScriptString**)&params[4] = TextInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
