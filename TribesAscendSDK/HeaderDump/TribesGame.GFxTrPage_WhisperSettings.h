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
	class GFxTrPage_WhisperSettings : public GFxTrPage
	{
	public:
		enum MENU_ACTION_WHISPER_NOTIFY_TYPE : byte
		{
			MAWNT_SHOWALL = 0,
			MAWNT_ONLYFRIENDS = 1,
			MAWNT_NOBODY = 2,
			MAVNT_MAX = 3,
			MENU_ACTION_WHISPER_NOTIFY_TYPE_MAX = 4,
		};
		ADD_STRUCT(int, CurrSetting, 356)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_WhisperSettings.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_WhisperSettings.FillData");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_WhisperSettings.FillOption");
			byte params[8] = { NULL };
			*(int*)&params[0] = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_WhisperSettings.SpecialAction");
			byte params[4] = { NULL };
			*(class GFxTrAction**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowModel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_WhisperSettings.ShowModel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
