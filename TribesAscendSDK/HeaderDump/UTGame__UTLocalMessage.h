#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTLocalMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTLocalMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTLocalMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTLocalMessage : public LocalMessage
	{
	public:
			class SoundNodeWave* AnnouncementSound( int MessageIndex, class Object* OptionalObject, class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTLocalMessage.AnnouncementSound" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = MessageIndex;
				*( class Object** )( params + 4 ) = OptionalObject;
				*( class PlayerController** )( params + 8 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SoundNodeWave** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, AnnouncementVolume, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShowPortrait, 0x1 )
			byte AnnouncementLevel( byte MessageIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTLocalMessage.AnnouncementLevel" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = MessageIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, AnnouncementDelay, 0xFFFFFFFF )
			bool AddAnnouncement( class UTAnnouncer* Announcer, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTLocalMessage.AddAnnouncement" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class UTAnnouncer** )params = Announcer;
				*( int* )( params + 4 ) = MessageIndex;
				*( class PlayerReplicationInfo** )( params + 8 ) = PRI;
				*( class Object** )( params + 12 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, AnnouncementPriority, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MessageArea, 0xFFFFFFFF )
			bool ShouldBeRemoved( class UTQueuedAnnouncement* MyAnnouncement, ScriptClass* NewAnnouncementClass, int NewMessageIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTLocalMessage.ShouldBeRemoved" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UTQueuedAnnouncement** )params = MyAnnouncement;
				*( ScriptClass** )( params + 4 ) = NewAnnouncementClass;
				*( int* )( params + 8 ) = NewMessageIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float GetPos( int Switch, class HUD* myHUD )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTLocalMessage.GetPos" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = Switch;
				*( class HUD** )( params + 4 ) = myHUD;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool KilledByVictoryMessage( int AnnouncementIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTLocalMessage.KilledByVictoryMessage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = AnnouncementIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
