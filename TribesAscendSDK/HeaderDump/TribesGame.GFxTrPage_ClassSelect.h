#pragma once
#include "TribesGame.GFxTrPage.h"
#include "GFxUI.GFxObject.h"
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
	class GFxTrPage_ClassSelect : public GFxTrPage
	{
	public:
		ADD_BOOL(bClassDeniedPopup, 372, 0x1)
		ADD_STRUCT(int, XPAmount, 368)
		ADD_STRUCT(int, GPAmount, 364)
		ADD_STRUCT(int, PurchasingClass, 360)
		ADD_STRUCT(int, FocusedClass, 356)
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58344);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int TakeFocus(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58345);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int ModifyAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58350);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void RefreshClassList()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58359);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58362);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int TakeAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58364);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58370);
			byte params[8] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		void ShowModel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58374);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool RequestActiveClass(int ClassId, int Loadout)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58375);
			byte params[12] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool CheckPricing(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58380);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class GFxObject* FillPricing(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58385);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		void OnPurchaseSuccess()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58392);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58393);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopupComplete(int Action, ScriptString* TextInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58403);
			byte params[16] = { NULL };
			*(int*)params = Action;
			*(ScriptString**)&params[4] = TextInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58406);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58410);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		ScriptString* GetEquipName(int equipType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58415);
			byte params[16] = { NULL };
			*(int*)params = equipType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
