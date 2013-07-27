#pragma once
#include "GameFramework.MobilePlayerInput.h"
namespace UnrealScript
{
	class UDKPlayerInput : public MobilePlayerInput
	{
	public:
		ScriptString* GetUDKBindNameFromCommand(ScriptString* BindCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerInput.GetUDKBindNameFromCommand");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = BindCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
	};
}
