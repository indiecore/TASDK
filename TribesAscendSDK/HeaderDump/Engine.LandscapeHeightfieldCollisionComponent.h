#pragma once
#include "Core.Object.Pointer.h"
#include "Core.Object.BoxSphereBounds.h"
#include "Engine.PrimitiveComponent.h"
#include "Core.Object.UntypedBulkData_Mirror.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LandscapeHeightfieldCollisionComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LandscapeHeightfieldCollisionComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LandscapeHeightfieldCollisionComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<BoxSphereBounds>, CachedBoxSphereBounds, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, RBHeightfield, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CollisionScale, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CollisionSizeQuads, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SectionBaseY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SectionBaseX, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UntypedBulkData_Mirror>, CollisionHeightData, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
