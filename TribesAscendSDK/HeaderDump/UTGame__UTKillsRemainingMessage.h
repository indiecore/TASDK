#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTKillsRemainingMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTKillsRemainingMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTKillsRemainingMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTKillsRemainingMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, KillsRemainStrings, 0xFFFFFFFF )
			ADD_OBJECT( SoundNodeWave, KillsRemainSounds )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
