#pragma once
#include "TribesGame.GFxTrPage.h"
#include "GFxUI.GFxObject.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Login : public GFxTrPage
	{
	public:
		enum MENU_ACTION_LOGIN : byte
		{
			MAL_LOAD = 0,
			MAL_SUBMIT = 1,
			MAL_BETAKEY = 2,
			MAL_EXIT = 3,
			MAL_HELPUSERNAME = 4,
			MAL_HELPPASSWORD = 5,
			MAL_NEWACCOUNT = 6,
			MAL_REMEMBERME = 7,
			MAL_MAX = 8,
		};
		ADD_STRUCT(ScriptString*, CreateAccountLabel, 464)
		ADD_STRUCT(ScriptString*, HelpPasswordLabel, 452)
		ADD_STRUCT(ScriptString*, HelpUsernameLabel, 440)
		ADD_STRUCT(ScriptString*, CheckboxLabel, 428)
		ADD_STRUCT(ScriptString*, PasswordLabel, 416)
		ADD_STRUCT(ScriptString*, UsernameLabel, 404)
		ADD_STRUCT(ScriptString*, BetaKeyLabel, 392)
		ADD_STRUCT(ScriptString*, AccountLabel, 380)
		ADD_STRUCT(ScriptString*, SubmitLabel, 368)
		ADD_STRUCT(ScriptString*, HelpLabel, 356)
		int TakeAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59464);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59468);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59471);
			byte params[8] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		void ShowModel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59485);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
