#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.FogVolumeConeDensityComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.FogVolumeConeDensityComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.FogVolumeConeDensityComponent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FogVolumeConeDensityComponent : public FogVolumeDensityComponent
	{
	public:
			ADD_VAR( ::FloatProperty, ConeMaxAngle, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ConeAxis, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConeRadius, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ConeVertex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxDensity, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
