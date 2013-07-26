#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SpeechRecognition.RecogVocabulary." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RecogVocabulary
	{
	public:
		ADD_VAR(::StrProperty, VocabName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
