#pragma once
#include "Core__Object.h"
#include "Engine__Texture2D.h"
#include "Engine__MaterialInterface.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.TerrainMaterial." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.TerrainMaterial." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.TerrainMaterial." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TerrainMaterial : public Object
	{
	public:
		ADD_VAR(::FloatProperty, DisplacementScale, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, DisplacementMap)
		ADD_OBJECT(MaterialInterface, Material)
		ADD_VAR(::FloatProperty, MappingPanV, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MappingPanU, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MappingRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MappingScale, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MappingType, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'LocalToMapping'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
