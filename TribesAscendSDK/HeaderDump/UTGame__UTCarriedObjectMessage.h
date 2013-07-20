#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTCarriedObjectMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTCarriedObjectMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTCarriedObjectMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTCarriedObjectMessage : public UTLocalMessage
	{
	public:
			ADD_OBJECT( SoundNodeWave, TakenSounds )
			ADD_OBJECT( SoundNodeWave, DroppedSounds )
			ADD_OBJECT( SoundNodeWave, ReturnSounds )
			ADD_VAR( ::StrProperty, KilledRed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, KilledBlue, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HasRed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HasBlue, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DroppedRed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DroppedBlue, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CaptureRed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CaptureBlue, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ReturnedRed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ReturnedBlue, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ReturnRed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ReturnBlue, 0xFFFFFFFF )
			void ClientReceive( class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCarriedObjectMessage.ClientReceive" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class PlayerController** )params = P;
				*( int* )( params + 4 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI_;
				*( class Object** )( params + 16 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class SoundNodeWave* AnnouncementSound( int MessageIndex, class Object* OptionalObject, class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCarriedObjectMessage.AnnouncementSound" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = MessageIndex;
				*( class Object** )( params + 4 ) = OptionalObject;
				*( class PlayerController** )( params + 8 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SoundNodeWave** )( params + function->return_val_offset() );
			}

			byte AnnouncementLevel( byte MessageIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCarriedObjectMessage.AnnouncementLevel" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = MessageIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetString( int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCarriedObjectMessage.GetString" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = Switch;
				*( bool* )( params + 4 ) = bPRI1HUD;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI_;
				*( class Object** )( params + 16 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool ShouldBeRemoved( class UTQueuedAnnouncement* MyAnnouncement, ScriptClass* NewAnnouncementClass, int NewMessageIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCarriedObjectMessage.ShouldBeRemoved" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UTQueuedAnnouncement** )params = MyAnnouncement;
				*( ScriptClass** )( params + 4 ) = NewAnnouncementClass;
				*( int* )( params + 8 ) = NewMessageIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShouldRemoveFlagAnnouncement( int MyMessageIndex, ScriptClass* NewAnnouncementClass, int NewMessageIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCarriedObjectMessage.ShouldRemoveFlagAnnouncement" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = MyMessageIndex;
				*( ScriptClass** )( params + 4 ) = NewAnnouncementClass;
				*( int* )( params + 8 ) = NewMessageIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AddAnnouncement( class UTAnnouncer* Announcer, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCarriedObjectMessage.AddAnnouncement" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class UTAnnouncer** )params = Announcer;
				*( int* )( params + 4 ) = MessageIndex;
				*( class PlayerReplicationInfo** )( params + 8 ) = PRI;
				*( class Object** )( params + 12 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool PartiallyDuplicates( int Switch1, int Switch2, class Object* OptionalObject1, class Object* OptionalObject2 )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCarriedObjectMessage.PartiallyDuplicates" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = Switch1;
				*( int* )( params + 4 ) = Switch2;
				*( class Object** )( params + 8 ) = OptionalObject1;
				*( class Object** )( params + 12 ) = OptionalObject2;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
