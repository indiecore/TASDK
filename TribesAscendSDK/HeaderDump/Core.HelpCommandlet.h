#pragma once
#include "Core.Commandlet.h"
namespace UnrealScript
{
	class HelpCommandlet : public Commandlet
	{
	public:
		int Main(ScriptString* Params)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.HelpCommandlet.Main");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Params;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
	};
}
