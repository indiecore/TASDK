#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.AmbientOcclusionEffect." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.AmbientOcclusionEffect." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.AmbientOcclusionEffect." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AmbientOcclusionEffect : public PostProcessEffect
	{
	public:
			ADD_VAR( ::FloatProperty, HistoryWeightConvergenceTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HistoryConvergenceTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FilterSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FilterDistanceScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EdgeDistanceScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EdgeDistanceThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HaloOcclusion, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HaloDistanceScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HaloDistanceThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OcclusionFadeoutMaxDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OcclusionFadeoutMinDistance, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, OcclusionQuality, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OcclusionAttenuation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OcclusionRadius, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAngleBasedSSAO, 0x2 )
			ADD_VAR( ::BoolProperty, SSAO2, 0x1 )
			ADD_VAR( ::FloatProperty, MinOcclusion, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OcclusionBias, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OcclusionScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OcclusionPower, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
