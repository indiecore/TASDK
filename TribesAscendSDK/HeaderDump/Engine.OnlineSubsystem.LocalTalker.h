#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineSubsystem.LocalTalker." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LocalTalker
	{
	public:
		ADD_VAR(::BoolProperty, bHasVoice, 0x1)
		ADD_VAR(::BoolProperty, bHasNetworkedVoice, 0x2)
		ADD_VAR(::BoolProperty, bIsRecognizingSpeech, 0x4)
		ADD_VAR(::BoolProperty, bWasTalking, 0x8)
		ADD_VAR(::BoolProperty, bIsTalking, 0x10)
		ADD_VAR(::BoolProperty, bIsRegistered, 0x20)
	};
}
#undef ADD_VAR
