#pragma once
#include "Engine.TranslatorTag.h"
namespace UnrealScript
{
	class StringsTag : public TranslatorTag
	{
	public:
		ScriptString* Translate(ScriptString* InArgument)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.StringsTag.Translate");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = InArgument;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
	};
}
