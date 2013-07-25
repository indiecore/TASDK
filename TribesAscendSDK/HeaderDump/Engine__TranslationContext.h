#pragma once
#include "Core__Object.h"
#include "Engine__TranslatorTag.h"
namespace UnrealScript
{
	class TranslationContext : public Object
	{
	public:
		bool RegisterTranslatorTag(class TranslatorTag* InTagHandler)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TranslationContext.RegisterTranslatorTag");
			byte* params = (byte*)malloc(8);
			*(class TranslatorTag**)params = InTagHandler;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
