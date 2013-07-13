#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTKillerMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTKillerMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTKillerMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTKillerMessage : public UTWeaponKillMessage
	{
	public:
			ADD_VAR( ::StrProperty, OtherKilledTrailer, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OtherKilled, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OtherKilledPrefix, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YouTeamKilledTrailer, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YouTeamKilled, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YouKilledTrailer, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YouKilled, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
