#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FracturedStaticMesh." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.FracturedStaticMesh." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FracturedStaticMesh : public StaticMesh
	{
	public:
		ADD_OBJECT(ParticleSystem, FragmentDestroyEffect)
		ADD_VAR(::FloatProperty, FragmentDestroyEffectScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FragmentHealthScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FragmentMinHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FragmentMaxHealth, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUniformFragmentHealth, 0x1)
		ADD_OBJECT(StaticMesh, SourceCoreMesh)
		ADD_VAR(::FloatProperty, CoreMeshScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSliceUsingCoreCollision, 0x1)
		ADD_VAR(::FloatProperty, ChunkLinVel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ChunkAngVel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ChunkLinHorizontalScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExplosionVelScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCompositeChunksExplodeOnImpact, 0x1)
		ADD_VAR(::BoolProperty, bFixIsolatedChunks, 0x1)
		ADD_VAR(::BoolProperty, bAlwaysBreakOffIsolatedIslands, 0x1)
		ADD_VAR(::BoolProperty, bSpawnPhysicsChunks, 0x1)
		ADD_VAR(::FloatProperty, ChanceOfPhysicsChunk, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExplosionChanceOfPhysicsChunk, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NormalPhysicsChunkScaleMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NormalPhysicsChunkScaleMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExplosionPhysicsChunkScaleMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExplosionPhysicsChunkScaleMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinConnectionSupportArea, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, DynamicOutsideMaterial)
		ADD_OBJECT(MaterialInterface, LoseChunkOutsideMaterial)
		ADD_VAR(::IntProperty, OutsideMaterialIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
