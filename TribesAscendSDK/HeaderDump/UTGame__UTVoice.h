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
			int GetAckMessageIndex( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.GetAckMessageIndex" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetFriendlyFireMessageIndex( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.GetFriendlyFireMessageIndex" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetGotYourBackMessageIndex( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.GetGotYourBackMessageIndex" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetNeedOurFlagMessageIndex( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.GetNeedOurFlagMessageIndex" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void ClientReceive( class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.ClientReceive" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class PlayerController** )( params + 0 ) = P;
				*( int* )( params + 4 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI_;
				*( class Object** )( params + 16 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class SoundNodeWave* AnnouncementSound( int MessageIndex, class Object* OptionalObject, class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.AnnouncementSound" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = MessageIndex;
				*( class Object** )( params + 4 ) = OptionalObject;
				*( class PlayerController** )( params + 8 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SoundNodeWave** )( params + function->return_val_offset() );
			}

			class SoundNodeWave* EnemySound( class PlayerController* PC, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.EnemySound" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( class Object** )( params + 4 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SoundNodeWave** )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetString( int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.GetString" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )( params + 0 ) = Switch;
				*( bool* )( params + 4 ) = bPRI1HUD;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI_;
				*( class Object** )( params + 16 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool AllowVoiceMessage( ScriptName MessageType, class UTPlayerController* PC, class PlayerController* Recipient )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.AllowVoiceMessage" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = MessageType;
				*( class UTPlayerController** )( params + 8 ) = PC;
				*( class PlayerController** )( params + 12 ) = Recipient;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SendVoiceMessage( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.SendVoiceMessage" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				*( ScriptClass** )( params + 16 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetMessageIndex( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.GetMessageIndex" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				*( ScriptClass** )( params + 16 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void InitStatusUpdate( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.InitStatusUpdate" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitCombatUpdate( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.InitCombatUpdate" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetHoldingFlagUpdate( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.SetHoldingFlagUpdate" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendLocalizedMessage( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType, int MessageIndex, class Object* LocationObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.SendLocalizedMessage" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				*( int* )( params + 16 ) = MessageIndex;
				*( class Object** )( params + 20 ) = LocationObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendEnemyFlagCarrierHereUpdate( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.SendEnemyFlagCarrierHereUpdate" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitSniperUpdate( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.InitSniperUpdate" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendEnemyStatusUpdate( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.SendEnemyStatusUpdate" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendKilledVehicleMessage( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.SendKilledVehicleMessage" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class SoundNodeWave* KilledVehicleSound( class PlayerController* PC, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.KilledVehicleSound" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( class Object** )( params + 4 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SoundNodeWave** )( params + function->return_val_offset() );
			}

			bool SendLocationUpdate( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType, class UTGame* G, class Pawn* StatusPawn, bool bDontSendMidfield )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.SendLocationUpdate" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				*( class UTGame** )( params + 16 ) = G;
				*( class Pawn** )( params + 20 ) = StatusPawn;
				*( bool* )( params + 24 ) = bDontSendMidfield;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SendInPositionMessage( class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.SendInPositionMessage" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( class PlayerReplicationInfo** )( params + 4 ) = Recipient;
				*( ScriptName* )( params + 8 ) = MessageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldBeRemoved( class UTQueuedAnnouncement* MyAnnouncement, ScriptClass* NewAnnouncementClass, int NewMessageIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.ShouldBeRemoved" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UTQueuedAnnouncement** )( params + 0 ) = MyAnnouncement;
				*( ScriptClass** )( params + 4 ) = NewAnnouncementClass;
				*( int* )( params + 8 ) = NewMessageIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AddAnnouncement( class UTAnnouncer* Announcer, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVoice.AddAnnouncement" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class UTAnnouncer** )( params + 0 ) = Announcer;
				*( int* )( params + 4 ) = MessageIndex;
				*( class PlayerReplicationInfo** )( params + 8 ) = PRI;
				*( class Object** )( params + 12 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
