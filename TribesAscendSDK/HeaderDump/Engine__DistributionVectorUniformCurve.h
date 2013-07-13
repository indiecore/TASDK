#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DistributionVectorUniformCurve." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DistributionVectorUniformCurve." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DistributionVectorUniformCurve." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DistributionVectorUniformCurve : public DistributionVector
	{
	public:
			ADD_VAR( ::ByteProperty, MirrorFlags, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LockedAxes, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUseExtremes, 0x4 )
			ADD_VAR( ::BoolProperty, bLockAxes2, 0x2 )
			ADD_VAR( ::BoolProperty, bLockAxes1, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
