#pragma once
#include "Core.Commandlet.h"
namespace UnrealScript
{
	class HelpCommandlet : public Commandlet
	{
	public:
		int Main(ScriptArray<wchar_t> Params)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.HelpCommandlet.Main");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Params;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
