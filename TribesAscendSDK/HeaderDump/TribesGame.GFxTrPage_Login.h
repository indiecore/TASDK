#pragma once
#include "TribesGame.GFxTrPage.h"
#include "GFxUI.GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Login." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Login : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, CreateAccountLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpPasswordLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpUsernameLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CheckboxLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PasswordLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, UsernameLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BetaKeyLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AccountLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SubmitLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpLabel, 0xFFFFFFFF)
		int TakeAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_Login.TakeAction");
			byte* params = (byte*)malloc(12);
			*(int*)params = ActionIndex;
			*(class GFxObject**)(params + 4) = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_Login.FillData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_Login.FillOption");
			byte* params = (byte*)malloc(8);
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 4);
			free(params);
			return returnVal;
		}
		void ShowModel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_Login.ShowModel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
