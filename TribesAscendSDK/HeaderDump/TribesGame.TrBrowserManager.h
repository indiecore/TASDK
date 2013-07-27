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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73715);
			byte params[12] = { NULL };
			*(ScriptString**)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OpenVideo(ScriptString* URL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73717);
			byte params[12] = { NULL };
			*(ScriptString**)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetLanguageString()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73719);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void Alert()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73721);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Gold()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73722);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Store()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73723);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Booster()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73724);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Support()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73725);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Profile()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73726);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ActivateKey()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73727);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RecoverPassword()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73728);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RecoverUsername()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73729);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassVideo(int Id)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73730);
			byte params[4] = { NULL };
			*(int*)params = Id;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateAccount(bool bUsingSteam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73732);
			byte params[4] = { NULL };
			*(bool*)params = bUsingSteam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetLangParam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73734);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
}
#undef ADD_STRUCT
