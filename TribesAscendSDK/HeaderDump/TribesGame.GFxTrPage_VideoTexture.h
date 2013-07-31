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
	class GFxTrPage_VideoTexture : public GFxTrPage
	{
	public:
		enum MENU_ACTION_VIDEOTEXTURE : byte
		{
			MAVT_MINIMAL = 0,
			MAVT_LOW = 1,
			MAVT_MEDIUM = 2,
			MAVT_HIGH = 3,
			MAVT_VERYHIGH = 4,
			MAVT_MAX = 5,
		};
		ADD_STRUCT(int, CurrGraphics, 360)
		ADD_STRUCT(int, SettingIndex, 356)
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61462);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61464);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61466);
			byte params[4] = { NULL };
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PerformChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61468);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61469);
			byte params[8] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
	};
}
#undef ADD_STRUCT
