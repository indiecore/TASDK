#pragma once
#include "UTGame.UTMutator.h"
#include "Engine.Actor.h"
namespace UnrealScript
{
	class UTMutator_NoPowerups : public UTMutator
	{
	public:
		bool CheckReplacement(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator_NoPowerups.CheckReplacement");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
