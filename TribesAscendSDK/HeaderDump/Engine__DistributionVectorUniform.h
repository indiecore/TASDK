#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DistributionVectorUniform." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DistributionVectorUniform." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DistributionVectorUniform." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DistributionVectorUniform : public DistributionVector
	{
	public:
			ADD_VAR( ::ByteProperty, MirrorFlags, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LockedAxes, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUseExtremes, 0x2 )
			ADD_VAR( ::BoolProperty, bLockAxes, 0x1 )
			ADD_STRUCT( ::VectorProperty, Min, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Max, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
