#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKForcedDirectionVolume." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKForcedDirectionVolume." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKForcedDirectionVolume." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKForcedDirectionVolume : public PhysicsVolume
	{
	public:
			ADD_STRUCT( ::VectorProperty, ArrowDirection, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bBlockSpectators, 0x8 )
			ADD_VAR( ::BoolProperty, bBlockPawns, 0x4 )
			ADD_VAR( ::BoolProperty, bDenyExit, 0x2 )
			ADD_VAR( ::BoolProperty, bIgnoreHoverboards, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
