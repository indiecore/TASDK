#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKSkelControl_PropellerBlade." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKSkelControl_PropellerBlade." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKSkelControl_PropellerBlade." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKSkelControl_PropellerBlade : public SkelControlSingleBone
	{
	public:
			ADD_VAR( ::FloatProperty, DesiredRotationsPerSecond, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RotationsPerSecond, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCounterClockwise, 0x1 )
			ADD_VAR( ::FloatProperty, SpinUpTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxRotationsPerSecond, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
