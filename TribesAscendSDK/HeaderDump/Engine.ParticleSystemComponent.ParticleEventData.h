#pragma once
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleSystemComponent.ParticleEventData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty ParticleSystemComponent.ParticleEventData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleEventData
	{
	public:
		ADD_STRUCT(::VectorProperty, Velocity, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Direction, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Location, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EmitterTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EventName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Type, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
