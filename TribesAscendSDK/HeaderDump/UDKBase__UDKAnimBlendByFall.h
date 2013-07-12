#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKAnimBlendByFall." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKAnimBlendByFall." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKAnimBlendByFall." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKAnimBlendByFall : public UDKAnimBlendBase
	{
	public:
			ADD_OBJECT( UDKAnimNodeJumpLeanOffset, CachedLeanNode )
			ADD_VAR( ::FloatProperty, LastFallingVelocity, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, FallState, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ToDblJumpUprightTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PreLandStartUprightTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PreLandTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDodgeFall, 0x4 )
			ADD_VAR( ::BoolProperty, bDidDoubleJump, 0x2 )
			ADD_VAR( ::BoolProperty, bIgnoreDoubleJumps, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
