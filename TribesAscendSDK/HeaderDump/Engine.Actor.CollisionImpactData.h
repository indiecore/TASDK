#pragma once
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Actor.CollisionImpactData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CollisionImpactData
	{
	public:
		ADD_STRUCT(::VectorProperty, TotalFrictionForceVector, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TotalNormalForceVector, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
