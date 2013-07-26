#pragma once
#include "Engine.SpeechRecognition.RecogUserData.h"
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SpeechRecognition." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SpeechRecognition." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SpeechRecognition : public Object
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, FnxVoiceData, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bInitialised, 0x2)
		ADD_VAR(::BoolProperty, bDirty, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RecogUserData>, InstanceData, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConfidenceThreshhold, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Language, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
