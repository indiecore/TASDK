#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKSkelControl_LookAt." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKSkelControl_LookAt." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKSkelControl_LookAt." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKSkelControl_LookAt : public SkelControlLookAt
	{
	public:
			ADD_VAR( ::FloatProperty, RollLimit, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PitchLimit, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, YawLimit, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShowPerAxisLimits, 0x8 )
			ADD_VAR( ::BoolProperty, bLimitRoll, 0x4 )
			ADD_VAR( ::BoolProperty, bLimitPitch, 0x2 )
			ADD_VAR( ::BoolProperty, bLimitYaw, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
