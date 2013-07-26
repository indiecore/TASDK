#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SpeechRecognition.RecognisableWord." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RecognisableWord
	{
	public:
		ADD_VAR(::StrProperty, PhoneticWord, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ReferenceWord, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Id, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
