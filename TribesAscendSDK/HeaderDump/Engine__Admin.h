#pragma once
#include "Engine__PlayerController.h"
namespace UnrealScript
{
	class Admin : public PlayerController
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Admin(ScriptArray<wchar_t> CommandLine)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.Admin");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = CommandLine;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerAdmin(ScriptArray<wchar_t> CommandLine)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.ServerAdmin");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = CommandLine;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KickBan(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.KickBan");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerKickBan(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.ServerKickBan");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Kick(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.Kick");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerKick(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.ServerKick");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayerList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.PlayerList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RestartMap()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.RestartMap");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerRestartMap()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.ServerRestartMap");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Switch(ScriptArray<wchar_t> URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.Switch");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerSwitch(ScriptArray<wchar_t> URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.ServerSwitch");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
