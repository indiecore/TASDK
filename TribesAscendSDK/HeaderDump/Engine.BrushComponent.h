#pragma once
#include "Core.Object.Pointer.h"
#include "Engine.PrimitiveComponent.h"
#include "Engine.Model.h"
#include "Engine.BrushComponent.KCachedConvexData_Mirror.h"
#include "Engine.KMeshProps.KAggregateGeom.h"
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
		ADD_STRUCT(::NonArithmeticProperty<KCachedConvexData_Mirror>, CachedPhysBrushData, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, BrushPhysDesc, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<KAggregateGeom>, BrushAggGeom, 0xFFFFFFFF)
		ADD_OBJECT(Model, Brush)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
