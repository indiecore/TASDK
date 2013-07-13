#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKGameObjective." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKGameObjective." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKGameObjective." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKGameObjective : public NavigationPoint
	{
	public:
			ADD_VAR( ::ByteProperty, DefenderTeamIndex, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, IconHudTexture )
			ADD_STRUCT( ::VectorProperty, HUDLocation, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUnderAttack, 0x2 )
			ADD_VAR( ::BoolProperty, bAllowOnlyShootable, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
