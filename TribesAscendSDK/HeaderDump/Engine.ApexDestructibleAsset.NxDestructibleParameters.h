#pragma once
#include "Engine.ApexDestructibleAsset.NxDestructibleParametersFlag.h"
#include "Core.Object.Box.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ApexDestructibleAsset.NxDestructibleParameters." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty ApexDestructibleAsset.NxDestructibleParameters." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NxDestructibleParameters
	{
	public:
		ADD_VAR(::FloatProperty, FractureImpulseScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GrbParticleSpacing, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GrbVolumeLimit, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<NxDestructibleParametersFlag>, Flags, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MassScaleExponent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxChunkSpeed, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Box>, ValidBounds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DebrisMaxSeparationMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DebrisMaxSeparationMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DebrisLifetimeMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DebrisLifetimeMin, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EssentialDepth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DebrisDepth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SupportDepth, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFormExtendedStructures, 0x1)
		ADD_VAR(::FloatProperty, DeformationPercentLimit, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageToPercentDeformation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaterialStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ImpactVelocityThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceToDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageCap, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageToRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageThreshold, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
