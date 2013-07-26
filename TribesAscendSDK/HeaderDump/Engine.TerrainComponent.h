#pragma once
#include "Core.Object.Pointer.h"
#include "Engine.PrimitiveComponent.h"
#include "Engine.TerrainComponent.TerrainBVTree.h"
#include "Engine.EngineTypes.LightMapRef.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.TerrainComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.TerrainComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TerrainComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::BoolProperty, bDisplayCollisionLevel, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, RBHeightfield, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TerrainBVTree>, BVTree, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FullBatch, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LightMapRef>, LightMap, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TrueSectionSizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TrueSectionSizeX, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SectionSizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SectionSizeX, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SectionBaseY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SectionBaseX, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, TerrainObject, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
