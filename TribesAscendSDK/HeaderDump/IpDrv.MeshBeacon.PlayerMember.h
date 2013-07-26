#pragma once
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MeshBeacon.PlayerMember." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty MeshBeacon.PlayerMember." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PlayerMember
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, NetId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Skill, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TeamNum, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
