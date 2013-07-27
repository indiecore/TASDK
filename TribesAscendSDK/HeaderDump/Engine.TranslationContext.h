#pragma once
#include "Core.Object.h"
#include "Engine.TranslatorTag.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TranslationContext : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<class TranslatorTag*>, TranslatorTags, 60)
		bool RegisterTranslatorTag(class TranslatorTag* InTagHandler)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TranslationContext.RegisterTranslatorTag");
			byte params[8] = { NULL };
			*(class TranslatorTag**)&params[0] = InTagHandler;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_STRUCT
