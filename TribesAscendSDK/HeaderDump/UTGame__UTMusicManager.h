#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTMusicManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTMusicManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTMusicManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTMusicManager : public Info
	{
	public:
			bool AlreadyInActionMusic(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMusicManager.AlreadyInActionMusic" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, MusicStartTime, 0xFFFFFFFF )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMusicManager.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartMusic(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMusicManager.StartMusic" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, LastBeat, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CurrentState, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MusicVolume, 0xFFFFFFFF )
			ADD_OBJECT( UTPlayerController, PlayerOwner )
			ADD_VAR( ::FloatProperty, CurrTempo, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrFadeFactor, 0xFFFFFFFF )
			void IntroFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMusicManager.IntroFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* CreateNewTrack( class SoundCue* MusicCue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMusicManager.CreateNewTrack" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SoundCue** )params = MusicCue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void MusicEvent( int NewEventIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMusicManager.MusicEvent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = NewEventIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, PendingEvent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PendingEventPlayTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PendingEventDelay, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bPendingAction, 0x1 )
			ADD_VAR( ::FloatProperty, LastActionEventTime, 0xFFFFFFFF )
			void ProcessMusicEvent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMusicManager.ProcessMusicEvent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, StingerVolumeMultiplier, 0xFFFFFFFF )
			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMusicManager.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangeTrack( byte NewState )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMusicManager.ChangeTrack" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = NewState;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
