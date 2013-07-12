#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.DynamicLightEnvironmentComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.DynamicLightEnvironmentComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.DynamicLightEnvironmentComponent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DynamicLightEnvironmentComponent : public LightEnvironmentComponent
	{
	public:
			ADD_VAR( ::FloatProperty, MinShadowAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BouncedLightingFactor, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, BoundsMethod, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LightShadowMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ShadowFilterQuality, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ShadowFadeResolution, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxShadowResolution, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinShadowResolution, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DominantShadowTransitionEndDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DominantShadowTransitionStartDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ModShadowFadeoutExponent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ModShadowFadeoutTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bOverrideOwnerLightingChannels, 0x2000 )
			ADD_VAR( ::BoolProperty, bIsCharacterLightEnvironment, 0x1000 )
			ADD_VAR( ::BoolProperty, bTraceFromClosestBoundsPoint, 0x800 )
			ADD_VAR( ::BoolProperty, bRequiresNonLatentUpdates, 0x400 )
			ADD_VAR( ::BoolProperty, bForceAllowLightEnvSphericalHarmonicLights, 0x200 )
			ADD_VAR( ::BoolProperty, bSynthesizeSHLight, 0x100 )
			ADD_VAR( ::BoolProperty, bSynthesizeDirectionalLight, 0x80 )
			ADD_VAR( ::BoolProperty, bDynamic, 0x40 )
			ADD_VAR( ::BoolProperty, bShadowFromEnvironment, 0x20 )
			ADD_VAR( ::BoolProperty, bUseBooleanEnvironmentShadowing, 0x10 )
			ADD_VAR( ::BoolProperty, bAffectedBySmallDynamicLights, 0x8 )
			ADD_VAR( ::BoolProperty, bForceCompositeAllLights, 0x4 )
			ADD_VAR( ::BoolProperty, bCompositeShadowsFromDynamicLights, 0x2 )
			ADD_VAR( ::BoolProperty, bCastShadows, 0x1 )
			ADD_VAR( ::FloatProperty, ShadowDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LightDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LightDesaturation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, AmbientShadowSourceDirection, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LightingBoundsScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumVolumeVisibilitySamples, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ShadowInterpolationSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinTimeBetweenFullUpdates, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InvisibleUpdateTime, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
