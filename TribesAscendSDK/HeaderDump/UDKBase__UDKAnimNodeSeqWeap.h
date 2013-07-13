#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKAnimNodeSeqWeap." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKAnimNodeSeqWeap." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKAnimNodeSeqWeap." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKAnimNodeSeqWeap : public UDKAnimNodeSequence
	{
	public:
			ADD_VAR( ::NameProperty, StingerAnim, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ShoulderRocketAnim, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SinglePistolAnim, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, DualPistolAnim, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, DefaultAnim, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
