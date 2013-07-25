#pragma once
#include "Engine__TranslatorTag.h"
namespace UnrealScript
{
	class StringsTag : public TranslatorTag
	{
	public:
		ScriptArray<wchar_t> Translate(ScriptArray<wchar_t> InArgument)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.StringsTag.Translate");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = InArgument;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
