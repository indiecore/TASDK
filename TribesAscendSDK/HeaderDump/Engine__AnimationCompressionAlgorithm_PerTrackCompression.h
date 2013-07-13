#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimationCompressionAlgorithm_PerTrackCompression." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimationCompressionAlgorithm_PerTrackCompression." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimationCompressionAlgorithm_PerTrackCompression." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimationCompressionAlgorithm_PerTrackCompression : public AnimationCompressionAlgorithm_RemoveLinearKeys
	{
	public:
			ADD_VAR( ::FloatProperty, PerturbationProbeSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxErrorPerTrackRatio, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TranslationErrorSourceRatio, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RotationErrorSourceRatio, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ParentingDivisorExponent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ParentingDivisor, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TrackHeightBias, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinKeysForResampling, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ResampledFramerate, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUseAdaptiveError2, 0x8 )
			ADD_VAR( ::BoolProperty, bUseOverrideForEndEffectors, 0x4 )
			ADD_VAR( ::BoolProperty, bUseAdaptiveError, 0x2 )
			ADD_VAR( ::BoolProperty, bResampleAnimation, 0x1 )
			ADD_VAR( ::FloatProperty, MaxAngleDiffBitwise, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxPosDiffBitwise, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxZeroingThreshold, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
