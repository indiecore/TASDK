#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTSeqAct_ScriptedVoiceMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTSeqAct_ScriptedVoiceMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTSeqAct_ScriptedVoiceMessage." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTSeqAct_ScriptedVoiceMessage : public SequenceAction
	{
	public:
			ADD_VAR( ::StrProperty, SpeakingCharacterName, 0xFFFFFFFF )
			ADD_OBJECT( SoundNodeWave, VoiceToPlay )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
