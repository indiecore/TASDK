#pragma once
#include "GameFramework__MobilePlayerInput.h"
namespace UnrealScript
{
	class UDKPlayerInput : public MobilePlayerInput
	{
	public:
		ScriptArray<wchar_t> GetUDKBindNameFromCommand(ScriptArray<wchar_t> BindCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPlayerInput.GetUDKBindNameFromCommand");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = BindCommand;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
