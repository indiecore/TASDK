#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.Model.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.BrushComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.BrushComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.BrushComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class BrushComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::BoolProperty, bBlockComplexCollisionTrace, 0x1)
		ADD_VAR(::IntProperty, CachedPhysBrushDataVersion, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.BrushComponent.KCachedConvexData_Mirror' for the property named 'CachedPhysBrushData'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'BrushPhysDesc'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.KMeshProps.KAggregateGeom' for the property named 'BrushAggGeom'!
		ADD_OBJECT(Model, Brush)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
