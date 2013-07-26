#pragma once
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineSubsystem.OnlinePlayerScore." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineSubsystem.OnlinePlayerScore." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlinePlayerScore
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, PlayerID, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TeamID, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Score, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
