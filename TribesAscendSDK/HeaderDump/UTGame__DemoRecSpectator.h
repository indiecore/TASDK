#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.DemoRecSpectator." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.DemoRecSpectator." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.DemoRecSpectator." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DemoRecSpectator : public UTPlayerController
	{
	public:
			ADD_VAR( ::FloatProperty, AutoSwitchPlayerInterval, 0xFFFFFFFF )
			ADD_OBJECT( PlayerReplicationInfo, MyRealViewTarget )
			ADD_VAR( ::BoolProperty, bAutoSwitchPlayers, 0x4 )
			ADD_VAR( ::BoolProperty, bLockRotationToViewTarget, 0x2 )
			ADD_VAR( ::BoolProperty, bFindPlayer, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
