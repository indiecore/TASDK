#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FracturedStaticMeshActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FracturedStaticMeshActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.FracturedStaticMeshActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FracturedStaticMeshActor : public Actor
	{
	public:
		ADD_OBJECT(MaterialInterface, MI_LoseChunkPreviousMaterial)
		ADD_OBJECT(SoundCue, SingleChunkFractureSound)
		ADD_OBJECT(SoundCue, ExplosionFractureSound)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.PhysEffectInfo' for the property named 'PartImpactEffect'!
		ADD_VAR(::FloatProperty, FractureCullMaxDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FractureCullMinDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ChunkHealthScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBreakChunksOnActorTouch, 0x2)
		ADD_VAR(::BoolProperty, bHasShownMissingSoundWarning, 0x1)
		ADD_VAR(::IntProperty, MaxPartsToSpawnAtOnce, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
