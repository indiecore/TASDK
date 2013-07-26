#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineSubsystem.SpeechRecognizedWord." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SpeechRecognizedWord
	{
	public:
		ADD_VAR(::IntProperty, WordId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, WordText, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Confidence, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
