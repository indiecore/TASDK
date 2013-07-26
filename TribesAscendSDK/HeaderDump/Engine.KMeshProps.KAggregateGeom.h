#pragma once
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " KMeshProps.KAggregateGeom." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty KMeshProps.KAggregateGeom." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class KAggregateGeom
	{
	public:
		ADD_VAR(::BoolProperty, bSkipCloseAndParallelChecks, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, RenderInfo, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
