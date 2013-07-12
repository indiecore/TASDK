#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrStormMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrStormMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrStormMessage." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrStormMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, FriendlyCoreDestroyed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FriendlyCore25Percent, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FriendlyCore50Percent, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FriendlyCore75Percent, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EnemyCoreDestroyed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EnemyCore25Percent, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EnemyCore50Percent, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EnemyCore75Percent, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EnemyCarrierShieldsDown, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FriendlyCarrierShieldsDown, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EnemyCarrierShields50Percent, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FriendlyCarrierShields50Percent, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ControlPointTransitioning, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ControlPointLost, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ControlPointWon, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
