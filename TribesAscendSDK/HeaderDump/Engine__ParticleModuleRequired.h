#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ParticleModuleRequired." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ParticleModuleRequired." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ParticleModuleRequired." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleModuleRequired : public ParticleModule
	{
	public:
			ADD_STRUCT( ::VectorProperty, NormalsCylinderDirection, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, NormalsSphereCenter, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DownsampleThresholdScreenFraction, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxDrawCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RandomImageChanges, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RandomImageTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SubImages_Vertical, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SubImages_Horizontal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EmitterDelayLow, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EmitterDelay, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, EmitterLoops, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EmitterDurationLow, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EmitterDuration, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUseMaxDrawCount, 0x800 )
			ADD_VAR( ::BoolProperty, bDirectUV, 0x400 )
			ADD_VAR( ::BoolProperty, bScaleUV, 0x200 )
			ADD_VAR( ::BoolProperty, bDelayFirstLoopOnly, 0x100 )
			ADD_VAR( ::BoolProperty, bEmitterDelayUseRange, 0x80 )
			ADD_VAR( ::BoolProperty, bDurationRecalcEachLoop, 0x40 )
			ADD_VAR( ::BoolProperty, bEmitterDurationUseRange, 0x20 )
			ADD_VAR( ::BoolProperty, bUseLegacyEmitterTime, 0x10 )
			ADD_VAR( ::BoolProperty, bRequiresSorting, 0x8 )
			ADD_VAR( ::BoolProperty, bKillOnCompleted, 0x4 )
			ADD_VAR( ::BoolProperty, bKillOnDeactivate, 0x2 )
			ADD_VAR( ::BoolProperty, bUseLocalSpace, 0x1 )
			ADD_VAR( ::ByteProperty, EmitterNormalsMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, InterpolationMethod, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ParticleBurstMethod, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, SortMode, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInterface, Material )
			ADD_VAR( ::ByteProperty, ScreenAlignment, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
