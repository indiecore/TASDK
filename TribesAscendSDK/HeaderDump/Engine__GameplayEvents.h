#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.GameplayEvents." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.GameplayEvents." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameplayEvents : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.GameplayEvents.GameSessionInformation' for the property named 'CurrentSessionInfo'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.GameplayEvents.GameplayEventsHeader' for the property named 'Header'!
		ADD_VAR(::StrProperty, StatsFileName, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'Archive'!
		// Here lies the not-yet-implemented method 'OpenStatsFile'
		// Here lies the not-yet-implemented method 'CloseStatsFile'
		// Here lies the not-yet-implemented method 'GetFilename'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
