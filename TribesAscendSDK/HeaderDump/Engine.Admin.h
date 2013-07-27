#pragma once
#include "Engine.PlayerController.h"
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
		void Admin(ScriptString* CommandLine)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.Admin");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = CommandLine;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerAdmin(ScriptString* CommandLine)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.ServerAdmin");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = CommandLine;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KickBan(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.KickBan");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerKickBan(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.ServerKickBan");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Kick(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.Kick");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerKick(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.ServerKick");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		void Switch(ScriptString* URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.Switch");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSwitch(ScriptString* URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Admin.ServerSwitch");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
