#pragma once
#include "TribesGame.GFxTrPage.h"
#include "GFxUI.GFxObject.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_BuyBoost : public GFxTrPage
	{
	public:
		ADD_STRUCT(ScriptString*, DescriptionLabel, 364)
		ADD_STRUCT(int, selectedVendorItemId, 360)
		ADD_STRUCT(int, selectedActionIdx, 356)
		int TakeFocus(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57896);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57900);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckPricing(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57905);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class GFxObject* FillPricing(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57910);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57919);
			byte params[8] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		void CheckDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57926);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57930);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		void ShowModel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57934);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int ModifyAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57936);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void PopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57940);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopupComplete(int Action, ScriptString* TextInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57947);
			byte params[16] = { NULL };
			*(int*)params = Action;
			*(ScriptString**)&params[4] = TextInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
