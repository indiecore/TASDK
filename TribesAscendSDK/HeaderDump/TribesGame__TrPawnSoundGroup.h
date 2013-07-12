#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrPawnSoundGroup." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrPawnSoundGroup." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrPawnSoundGroup." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrPawnSoundGroup : public UTPawnSoundGroup
	{
	public:
			ADD_OBJECT( SoundCue, m_RechargeHealthSound3p )
			ADD_OBJECT( SoundCue, m_ShieldPackLoopSound1p )
			ADD_OBJECT( SoundCue, m_ShieldPackLoopSound3p )
			ADD_OBJECT( SoundCue, m_StealthPackLoopSound1p )
			ADD_OBJECT( SoundCue, m_RageLoopSound1p )
			ADD_OBJECT( SoundCue, m_RageLoopSound3p )
			ADD_OBJECT( SoundCue, m_JammerPackLoopSound1p )
			ADD_OBJECT( SoundCue, m_JetpackLoopSound )
			ADD_OBJECT( SoundCue, m_LowHealthSound )
			ADD_OBJECT( SoundCue, m_RechargeHealthSound )
			ADD_OBJECT( SoundCue, m_BlinkPackSound3p )
			ADD_OBJECT( SoundCue, m_BlinkPackSound1p )
			ADD_OBJECT( SoundCue, m_RageDeactivateSound3p )
			ADD_OBJECT( SoundCue, m_RageDeactivateSound1p )
			ADD_OBJECT( SoundCue, m_RageActivateSound3p )
			ADD_OBJECT( SoundCue, m_RageActivateSound1p )
			ADD_OBJECT( SoundCue, m_JammerPackLoopSound3p )
			ADD_OBJECT( SoundCue, m_JammerPackDeactivateSound3p )
			ADD_OBJECT( SoundCue, m_JammerPackDeactivateSound1p )
			ADD_OBJECT( SoundCue, m_JammerPackActivateSound3p )
			ADD_OBJECT( SoundCue, m_JammerPackActivateSound1p )
			ADD_OBJECT( SoundCue, m_StealthPackLoopSound3p )
			ADD_OBJECT( SoundCue, m_StealthPackDeactivateSound3p )
			ADD_OBJECT( SoundCue, m_StealthPackDeactivateSound1p )
			ADD_OBJECT( SoundCue, m_StealthPackActivateSound3p )
			ADD_OBJECT( SoundCue, m_StealthPackActivateSound1p )
			ADD_OBJECT( SoundCue, m_ShieldPackDeactivateSound3p )
			ADD_OBJECT( SoundCue, m_ShieldPackDeactivateSound1p )
			ADD_OBJECT( SoundCue, m_ShieldPackActivateSound3p )
			ADD_OBJECT( SoundCue, m_ShieldPackActivateSound1p )
			ADD_OBJECT( SoundCue, m_JetpackCooldownSound )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
