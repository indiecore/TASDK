#pragma once
#include "TribesGame.GFxTrPage.h"
#include "GFxUI.GFxObject.h"
#include "TribesGame.GFxTrAction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_VideoWindow : public GFxTrPage
	{
	public:
		enum MENU_ACTION_VIDEOWINDOW : byte
		{
			MAVW_FULLSCREEN = 0,
			MAVW_WINDOWED = 1,
			MAVW_BORDERLESS = 2,
			MAVW_MAX = 3,
		};
		ADD_STRUCT(int, CurrWindow, 356)
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61477);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61479);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61481);
			byte params[4] = { NULL };
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61483);
			byte params[8] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
	};
}
#undef ADD_STRUCT
