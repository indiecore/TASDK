#pragma once
#include "GameFramework.MobilePlayerInput.h"
namespace UnrealScript
{
	class UDKPlayerInput : public MobilePlayerInput
	{
	public:
		ScriptString* GetUDKBindNameFromCommand(ScriptString* BindCommand)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35283);
			byte params[24] = { NULL };
			*(ScriptString**)params = BindCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
	};
}
