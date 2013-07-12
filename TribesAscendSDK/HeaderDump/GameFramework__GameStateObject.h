#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.GameStateObject." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.GameStateObject." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.GameStateObject." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameStateObject : public GameplayEventsHandler
	{
	public:
			ADD_VAR( ::IntProperty, MaxRoundNumber, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RoundNumber, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsRoundStarted, 0x2 )
			ADD_VAR( ::BoolProperty, bIsMatchStarted, 0x1 )
			ADD_VAR( ::ByteProperty, SessionType, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
