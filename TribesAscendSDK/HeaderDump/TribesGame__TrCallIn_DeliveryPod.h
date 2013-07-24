#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCallIn_DeliveryPod." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrCallIn_DeliveryPod." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCallIn_DeliveryPod." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCallIn_DeliveryPod : public Actor
	{
	public:
		ADD_VAR(::FloatProperty, Speed, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TargetImpactPoint, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, TargetHitNormal, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, LifeAfterImpact, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, ImpactSound)
		ADD_OBJECT(SoundCue, FallingSound)
		ADD_OBJECT(ParticleSystem, DeliveryPodImpactTemplate)
		ADD_OBJECT(ParticleSystem, DeliveryPodParticleTemplate)
		ADD_VAR(::FloatProperty, DecalDissolveTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HitDecalWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HitDecalHeight, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceTimeVarying, PodHitDecal)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
