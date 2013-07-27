#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrBrowserManager : public Object
	{
	public:
		ADD_STRUCT(ScriptString*, URLCreateSteamAccount, 204)
		ADD_STRUCT(ScriptString*, URLRecoverUsername, 192)
		ADD_STRUCT(ScriptString*, URLRecoverPassword, 180)
		ADD_STRUCT(ScriptString*, URLCreateAccount, 168)
		ADD_STRUCT(ScriptString*, URLActivateKey, 156)
		ADD_STRUCT(ScriptString*, URLClassVideo, 144)
		ADD_STRUCT(ScriptString*, URLRedirect, 132)
		ADD_STRUCT(ScriptString*, URLProfile, 120)
		ADD_STRUCT(ScriptString*, URLSupport, 108)
		ADD_STRUCT(ScriptString*, URLBooster, 96)
		ADD_STRUCT(ScriptString*, URLStore, 84)
		ADD_STRUCT(ScriptString*, URLAlert, 72)
		ADD_STRUCT(ScriptString*, URLGold, 60)
		void OpenURL(ScriptString* URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.OpenURL");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OpenVideo(ScriptString* URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.OpenVideo");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetLanguageString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.GetLanguageString");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void Alert()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.Alert");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Gold()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.Gold");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Store()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.Store");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Booster()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.Booster");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Support()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.Support");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Profile()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.Profile");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ActivateKey()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.ActivateKey");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RecoverPassword()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.RecoverPassword");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RecoverUsername()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.RecoverUsername");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassVideo(int Id)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.ClassVideo");
			byte params[4] = { NULL };
			*(int*)&params[0] = Id;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateAccount(bool bUsingSteam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.CreateAccount");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bUsingSteam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetLangParam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.GetLangParam");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
	};
}
#undef ADD_STRUCT
