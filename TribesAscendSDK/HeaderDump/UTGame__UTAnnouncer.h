#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTAnnouncer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTAnnouncer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTAnnouncer." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTAnnouncer : public Info
	{
	public:
			ADD_VAR( ::StrProperty, UTVoiceSoundCueSoundCue, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, UTVoiceSoundCue )
			ADD_VAR( ::StrProperty, CustomAnnouncerSoundCue, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, AnnouncerSoundCue )
			ADD_OBJECT( UTPlayerController, PlayerOwner )
			ADD_OBJECT( UTQueuedAnnouncement, Queue )
			ADD_VAR( ::IntProperty, PlayingAnnouncementIndex, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, PlayingAnnouncementClass )
			ADD_VAR( ::ByteProperty, AnnouncerLevel, 0xFFFFFFFF )
			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTAnnouncer.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTAnnouncer.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayNextAnnouncement(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTAnnouncer.PlayNextAnnouncement" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayAnnouncementNow( ScriptClass* InMessageClass, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTAnnouncer.PlayAnnouncementNow" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )params = InMessageClass;
				*( int* )( params + 4 ) = MessageIndex;
				*( class PlayerReplicationInfo** )( params + 8 ) = PRI;
				*( class Object** )( params + 12 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AnnouncementFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTAnnouncer.AnnouncementFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayAnnouncement( ScriptClass* InMessageClass, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTAnnouncer.PlayAnnouncement" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )params = InMessageClass;
				*( int* )( params + 4 ) = MessageIndex;
				*( class PlayerReplicationInfo** )( params + 8 ) = PRI;
				*( class Object** )( params + 12 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
