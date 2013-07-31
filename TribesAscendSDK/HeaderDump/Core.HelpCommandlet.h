#pragma once
#include "Core.Commandlet.h"
namespace UnrealScript
{
	class HelpCommandlet : public Commandlet
	{
	public:
		int Main(ScriptString* Params)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3458);
			byte params[16] = { NULL };
			*(ScriptString**)params = Params;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
	};
}
