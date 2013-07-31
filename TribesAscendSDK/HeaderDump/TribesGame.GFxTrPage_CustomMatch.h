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
	class GFxTrPage_CustomMatch : public GFxTrPage
	{
	public:
		ADD_STRUCT(int, SERVERS_PER_PAGE, 432)
		ADD_STRUCT(ScriptString*, QueueJoinName, 420)
		ADD_STRUCT(int, PopupNumber, 416)
		ADD_STRUCT(int, ServerIndex, 412)
		ADD_BOOL(bWaitingForJoinPopup, 408, 0x10)
		ADD_BOOL(bFilterPopup, 408, 0x8)
		ADD_BOOL(bRefresh, 408, 0x4)
		ADD_BOOL(bFilterEmpty, 408, 0x2)
		ADD_BOOL(bFilterFull, 408, 0x1)
		ADD_STRUCT(ScriptString*, ServerNameFilter, 396)
		ADD_STRUCT(ScriptString*, MapNameFilter, 384)
		ADD_STRUCT(int, FilterServerNameNum, 380)
		ADD_STRUCT(int, FilterOwnerNum, 376)
		ADD_STRUCT(int, FilterFullNum, 372)
		ADD_STRUCT(int, FilterEmptyNum, 368)
		ADD_STRUCT(int, FilterMapNameNum, 364)
		ADD_STRUCT(int, FilterRegionNum, 360)
		ADD_STRUCT(int, RefreshNum, 356)
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58504);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58506);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int TakeFocus(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58509);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int TakeAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58513);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void PopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58520);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopupComplete(int Action, ScriptString* TextInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58528);
			byte params[16] = { NULL };
			*(int*)params = Action;
			*(ScriptString**)&params[4] = TextInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillServerBrowser()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58531);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)params;
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58566);
			byte params[8] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		void ActionUp()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58574);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ActionDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58575);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetLevelReq(int Min, int Max)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58576);
			byte params[20] = { NULL };
			*(int*)params = Min;
			*(int*)&params[4] = Max;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		void WaitPopup(ScriptString* ServerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58580);
			byte params[12] = { NULL };
			*(ScriptString**)params = ServerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowModel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58582);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
