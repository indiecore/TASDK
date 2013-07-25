#pragma once
#include "Core__Object.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineSubsystemMcts.OnlineVoiceInterfaceMcts." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineVoiceInterfaceMcts : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.LocalTalkerMcts' for the property named 'CurrentLocalTalker'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VoiceEnginePtr'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'MctsSubsystem'!
	};
}
#undef ADD_STRUCT
