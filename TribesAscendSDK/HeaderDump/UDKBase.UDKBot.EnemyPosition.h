#pragma once
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBot.EnemyPosition." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBot.EnemyPosition." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class EnemyPosition
	{
	public:
		ADD_VAR(::FloatProperty, Time, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Velocity, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Position, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
