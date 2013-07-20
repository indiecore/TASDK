#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrPlayerVoice." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrPlayerVoice." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrPlayerVoice." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrPlayerVoice : public TrDevice
	{
	public:
			void PlaySoundEx( byte Command, class TrPlayerController* TrPC, class PlayerReplicationInfo* InstigatorPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerVoice.PlaySoundEx" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )params = Command;
				*( class TrPlayerController** )( params + 4 ) = TrPC;
				*( class PlayerReplicationInfo** )( params + 8 ) = InstigatorPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlaySoundContext( class TrPlayerController* TrPC, byte ContextActor, byte ContextLocation, bool bEnemyLocation, class PlayerReplicationInfo* InstigatorPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerVoice.PlaySoundContext" );
				byte *params = ( byte* )( malloc( 14 ) );
				*( class TrPlayerController** )params = TrPC;
				*( byte* )( params + 4 ) = ContextActor;
				*( byte* )( params + 5 ) = ContextLocation;
				*( bool* )( params + 8 ) = bEnemyLocation;
				*( class PlayerReplicationInfo** )( params + 12 ) = InstigatorPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayRandomSample( class TrPlayerController* TrPC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerVoice.PlayRandomSample" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )params = TrPC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
