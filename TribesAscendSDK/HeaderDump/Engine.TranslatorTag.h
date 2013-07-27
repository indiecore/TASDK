#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TranslatorTag : public Object
	{
	public:
		ADD_STRUCT(ScriptName, Tag, 60)
		ScriptString* Translate(ScriptString* InArgument)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TranslatorTag.Translate");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = InArgument;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
	};
}
#undef ADD_STRUCT
