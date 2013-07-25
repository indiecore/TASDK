#pragma once
#include "Engine__PrimitiveComponent.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.BoxSphereBounds' for the property named 'CachedBoxSphereBounds'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'RBHeightfield'!
		ADD_VAR(::FloatProperty, CollisionScale, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CollisionSizeQuads, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SectionBaseY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SectionBaseX, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.UntypedBulkData_Mirror' for the property named 'CollisionHeightData'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
