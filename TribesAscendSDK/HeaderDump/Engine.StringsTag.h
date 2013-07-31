#pragma once
#include "Engine.TranslatorTag.h"
namespace UnrealScript
{
	class StringsTag : public TranslatorTag
	{
	public:
		ScriptString* Translate(ScriptString* InArgument)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27224);
			byte params[24] = { NULL };
			*(ScriptString**)params = InArgument;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
	};
}
