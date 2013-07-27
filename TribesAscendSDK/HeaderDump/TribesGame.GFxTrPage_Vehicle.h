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
	class GFxTrPage_Vehicle : public GFxTrPage
	{
	public:
		struct VehicleOption
		{
		public:
			ADD_STRUCT(ScriptString*, DisplayName, 28)
			ADD_STRUCT(ScriptString*, ClassName, 16)
			ADD_STRUCT(int, MaxCount, 12)
			ADD_STRUCT(int, Count, 8)
			ADD_STRUCT(int, Icon, 4)
			ADD_STRUCT(int, Cost, 0)
		};
		ADD_STRUCT(int, PlayerCredits, 356)
		ADD_STRUCT(ScriptArray<GFxTrPage_Vehicle::VehicleOption>, VehicleOptions, 360)
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61332);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61333);
			byte params[4] = { NULL };
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearActions()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61336);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int TakeAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61338);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void AddOption(ScriptString* ClassName, ScriptString* DisplayName, int Cost, int Icon, int Count, int MaxCount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61342);
			byte params[40] = { NULL };
			*(ScriptString**)params = ClassName;
			*(ScriptString**)&params[12] = DisplayName;
			*(int*)&params[24] = Cost;
			*(int*)&params[28] = Icon;
			*(int*)&params[32] = Count;
			*(int*)&params[36] = MaxCount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61350);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillOptions(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61352);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61357);
			byte params[8] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		void ShowModel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61362);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
