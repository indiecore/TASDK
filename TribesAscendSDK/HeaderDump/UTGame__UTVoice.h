#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTVoice." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTVoice." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTVoice." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTVoice : public UTLocalMessage
	{
	public:
			ADD_VAR( ::IntProperty, LocationSpeechOffset, 0xFFFFFFFF )
			ADD_OBJECT( SoundNodeWave, GotOurFlagSound )
			ADD_OBJECT( SoundNodeWave, MidfieldSound )
			ADD_OBJECT( SoundNodeWave, EnemyFlagCarrierLowSound )
			ADD_OBJECT( SoundNodeWave, EnemyFlagCarrierHighSound )
			ADD_OBJECT( SoundNodeWave, EnemyFlagCarrierHereSound )
			ADD_OBJECT( SoundNodeWave, EnemyFlagCarrierSound )
			ADD_OBJECT( SoundNodeWave, IncomingSound )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
