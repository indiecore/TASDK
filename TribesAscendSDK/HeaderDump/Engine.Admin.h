#pragma once
#include "Engine.PlayerController.h"
namespace UnrealScript
{
	class Admin : public PlayerController
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9627);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Admin(ScriptString* CommandLine)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9628);
			byte params[12] = { NULL };
			*(ScriptString**)params = CommandLine;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerAdmin(ScriptString* CommandLine)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9630);
			byte params[12] = { NULL };
			*(ScriptString**)params = CommandLine;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KickBan(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9633);
			byte params[12] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerKickBan(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9635);
			byte params[12] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Kick(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9637);
			byte params[12] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerKick(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9639);
			byte params[12] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayerList()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9641);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RestartMap()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9643);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerRestartMap()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9644);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Switch(ScriptString* URL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9645);
			byte params[12] = { NULL };
			*(ScriptString**)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSwitch(ScriptString* URL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9647);
			byte params[12] = { NULL };
			*(ScriptString**)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
