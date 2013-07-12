#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTVictimMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTVictimMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTVictimMessage." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTVictimMessage : public UTWeaponKillMessage
	{
	public:
			ADD_VAR( ::StrProperty, TelefragString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ViperKamikazeString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ScorpionKamikazeString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SpiderMineString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RunOverString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OrbSuicideString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, KilledByTrailer, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YouWereKilledBy, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
