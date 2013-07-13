#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTTeamGameMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTTeamGameMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTTeamGameMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTTeamGameMessage : public UTLocalMessage
	{
	public:
			ADD_OBJECT( SoundNodeWave, AnnouncerSounds )
			ADD_VAR( ::StrProperty, YouAreOnBlueMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YouAreOnRedMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RequestTeamSwapPostfix, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RequestTeamSwapPrefix, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
