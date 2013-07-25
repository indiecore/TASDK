#pragma once
#include "Core__Object.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Engine.KMeshProps.KAggregateGeom' for the property named 'AggGeom'!
		ADD_STRUCT(::VectorProperty, COMNudge, 0xFFFFFFFF
	};
}
#undef ADD_STRUCT
