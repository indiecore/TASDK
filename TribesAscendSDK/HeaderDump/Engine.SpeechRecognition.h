#pragma once
#include "Core.Object.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'FnxVoiceData'!
		ADD_VAR(::BoolProperty, bInitialised, 0x2)
		ADD_VAR(::BoolProperty, bDirty, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Engine.SpeechRecognition.RecogUserData' for the property named 'InstanceData'!
		ADD_VAR(::FloatProperty, ConfidenceThreshhold, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Language, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
