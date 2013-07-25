#pragma once
#include "Engine__ReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.TeamInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.TeamInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TeamInfo : public ReplicationInfo
	{
	public:
		ADD_VAR(::IntProperty, TeamIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Score, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'TeamColor'!
		ADD_VAR(::IntProperty, Size, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TeamName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
