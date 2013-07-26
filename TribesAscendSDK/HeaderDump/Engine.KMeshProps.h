#pragma once
#include "Engine.KMeshProps.KAggregateGeom.h"
#include "Core.Object.h"
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.KMeshProps." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class KMeshProps : public Object
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<KAggregateGeom>, AggGeom, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, COMNudge, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
