#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameExplosionActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameExplosionActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameExplosionActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameExplosionActor : public Actor
	{
	public:
		ADD_STRUCT(::VectorProperty, ExplosionDirection, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, DirectionalExplosionMinDot, 0xFFFFFFFF)
		ADD_OBJECT(Controller, AttacheeController)
		ADD_OBJECT(Actor, Attachee)
		ADD_STRUCT(::VectorProperty, HitLocationFromPhysMaterialTrace, 0xFFFFFFFF
		ADD_OBJECT(Actor, HitActorFromPhysMaterialTrace)
		ADD_OBJECT(Controller, InstigatorController)
		ADD_OBJECT(GameExplosion, ExplosionTemplate)
		ADD_VAR(::FloatProperty, RadialBlurMaxBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadialBlurFadeTimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadialBlurFadeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LightInitialBrightness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LightFadeTimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LightFadeTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDrawDebug, 0x4)
		ADD_VAR(::BoolProperty, bExplodeMoreThanOnce, 0x2)
		ADD_VAR(::BoolProperty, bHasExploded, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
