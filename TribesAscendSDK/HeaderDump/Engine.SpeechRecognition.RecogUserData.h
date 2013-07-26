#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SpeechRecognition.RecogUserData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RecogUserData
	{
	public:
		ADD_VAR(::IntProperty, ActiveVocabularies, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
