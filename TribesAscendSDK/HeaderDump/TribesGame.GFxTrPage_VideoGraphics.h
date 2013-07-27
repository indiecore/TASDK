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
	class GFxTrPage_VideoGraphics : public GFxTrPage
	{
	public:
		enum MENU_ACTION_VIDEOGRAPHICS : byte
		{
			MAVG_MINIMAL = 0,
			MAVG_LOW = 1,
			MAVG_MEDIUM = 2,
			MAVG_HIGH = 3,
			MAVG_VERYHIGH = 4,
			MAVG_MAX = 5,
		};
		ADD_STRUCT(int, CurrGraphics, 356)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_VideoGraphics.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_VideoGraphics.FillData");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_VideoGraphics.SpecialAction");
			byte params[4] = { NULL };
			*(class GFxTrAction**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_VideoGraphics.FillOption");
			byte params[8] = { NULL };
			*(int*)&params[0] = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
	};
}
#undef ADD_STRUCT
