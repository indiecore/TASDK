#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrBrowserManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrBrowserManager : public Object
	{
	public:
		ADD_VAR(::StrProperty, URLCreateSteamAccount, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLRecoverUsername, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLRecoverPassword, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLCreateAccount, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLActivateKey, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLClassVideo, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLRedirect, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLProfile, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLSupport, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLBooster, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLStore, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLAlert, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLGold, 0xFFFFFFFF)
		void OpenURL(ScriptArray<wchar_t> URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.OpenURL");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OpenVideo(ScriptArray<wchar_t> URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.OpenVideo");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetLanguageString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.GetLanguageString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(int*)params = Id;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateAccount(bool bUsingSteam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.CreateAccount");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bUsingSteam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetLangParam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBrowserManager.GetLangParam");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
