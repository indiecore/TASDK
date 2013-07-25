#pragma once
#include "Engine__LocalPlayer.h"
#include "GFxUI__GFxObject.h"
#include "UDKBase__UDKPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUIView." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxUIView : public GFxObject
	{
	public:
		ADD_VAR(::BoolProperty, bRequiresNetwork, 0x1)
		bool HasLinkConnection()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.HasLinkConnection");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class LocalPlayer* GetPlayerOwner(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.GetPlayerOwner");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class LocalPlayer**)(params + 4);
			free(params);
			return returnVal;
		}
		class UDKPlayerController* GetUDKPlayerOwner(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.GetUDKPlayerOwner");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UDKPlayerController**)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetPlayerName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.GetPlayerName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool IsLoggedIn(int ControllerId, bool bRequireOnlineLogin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.IsLoggedIn");
			byte* params = (byte*)malloc(12);
			*(int*)params = ControllerId;
			*(bool*)(params + 4) = bRequireOnlineLogin;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetCommonOptionsURL()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.GetCommonOptionsURL");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		int GetPlayerIndex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.GetPlayerIndex");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetPlayerControllerId(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.GetPlayerControllerId");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void ConsoleCommand(ScriptArray<wchar_t> Cmd, bool bWriteToLog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.ConsoleCommand");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Cmd;
			*(bool*)(params + 12) = bWriteToLog;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
