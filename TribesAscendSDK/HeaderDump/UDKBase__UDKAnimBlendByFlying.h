#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKAnimBlendByFlying." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKAnimBlendByFlying." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKAnimBlendByFlying." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKAnimBlendByFlying : public UDKAnimBlendBase
	{
	public:
			ADD_VAR( ::NameProperty, EndingAnimName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bHasEndingAnim, 0x2 )
			ADD_VAR( ::BoolProperty, bHasStartingAnim, 0x1 )
			ADD_VAR( ::NameProperty, StartingAnimName, 0xFFFFFFFF )
			ADD_OBJECT( AnimNodeAimOffset, FlyingDir )
			ADD_OBJECT( UDKAnimBlendBase, FlyingMode )
			ADD_OBJECT( UDKPawn, Pawn )
			ADD_VAR( ::ByteProperty, FlyingState, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
