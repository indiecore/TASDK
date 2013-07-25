#pragma once
#include "Engine__OnlineSubsystem.h"
#include "Engine__OnlineGameSettings.h"
#include "Engine__LocalPlayer.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPartySettings." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPartySettings : public OnlineGameSettings
	{
	public:
		ADD_OBJECT(OnlineSubsystem, OnlineSub)
		void Init(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPartySettings.Init");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Close()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPartySettings.Close");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPartySettings.OnLoginChange");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RefreshMembersList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPartySettings.RefreshMembersList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
