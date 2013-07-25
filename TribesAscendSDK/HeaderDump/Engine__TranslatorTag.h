#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.TranslatorTag." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TranslatorTag : public Object
	{
	public:
		ADD_VAR(::NameProperty, Tag, 0xFFFFFFFF)
		ScriptArray<wchar_t> Translate(ScriptArray<wchar_t> InArgument)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TranslatorTag.Translate");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = InArgument;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
