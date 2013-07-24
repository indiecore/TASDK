#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkeletalMeshActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SkeletalMeshActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SkeletalMeshActor : public Actor
	{
	public:
		ADD_VAR(::FloatProperty, SavedCurrentTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SavedAnimSeqName, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, ReplicatedMaterial)
		ADD_OBJECT(SkeletalMesh, ReplicatedMesh)
		ADD_VAR(::BoolProperty, bCollideActors_OldValue, 0x8)
		ADD_VAR(::BoolProperty, bForceSaveInCheckpoint, 0x4)
		ADD_VAR(::BoolProperty, bShouldDoAnimNotifies, 0x2)
		ADD_VAR(::BoolProperty, bDamageAppliesImpulse, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
