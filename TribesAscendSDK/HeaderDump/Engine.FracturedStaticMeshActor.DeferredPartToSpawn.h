#pragma once
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " FracturedStaticMeshActor.DeferredPartToSpawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty FracturedStaticMeshActor.DeferredPartToSpawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DeferredPartToSpawn
	{
	public:
		ADD_VAR(::BoolProperty, bExplosion, 0x1)
		ADD_VAR(::FloatProperty, RelativeScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, InitialAngVel, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, InitialVel, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ChunkIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
