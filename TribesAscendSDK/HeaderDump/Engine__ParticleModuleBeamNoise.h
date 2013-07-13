#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ParticleModuleBeamNoise." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ParticleModuleBeamNoise." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ParticleModuleBeamNoise." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleModuleBeamNoise : public ParticleModuleBeamBase
	{
	public:
			ADD_VAR( ::FloatProperty, FrequencyDistance, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NoiseTessellation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NoiseTension, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NoiseLockTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NoiseLockRadius, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Frequency_LowRange, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Frequency, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bApplyNoiseScale, 0x80 )
			ADD_VAR( ::BoolProperty, bTargetNoise, 0x40 )
			ADD_VAR( ::BoolProperty, bUseNoiseTangents, 0x20 )
			ADD_VAR( ::BoolProperty, bOscillate, 0x10 )
			ADD_VAR( ::BoolProperty, bNoiseLock, 0x8 )
			ADD_VAR( ::BoolProperty, bSmooth, 0x4 )
			ADD_VAR( ::BoolProperty, bNRScaleEmitterTime, 0x2 )
			ADD_VAR( ::BoolProperty, bLowFreq_Enabled, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
