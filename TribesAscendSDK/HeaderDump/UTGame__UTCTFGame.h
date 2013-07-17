#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTCTFGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTCTFGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTCTFGame." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTCTFGame : public UTTeamGame
	{
	public:
			ADD_OBJECT( ScriptClass, AnnouncerMessageClass )
			ADD_OBJECT( UTCTFFlag, Flags )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCTFGame.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetEndGameFocus( class PlayerReplicationInfo* Winner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCTFGame.SetEndGameFocus" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Winner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetHandicapNeed( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCTFGame.GetHandicapNeed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool GetLocationFor( class Pawn* StatusPawn, class Actor* &LocationObject, int &MessageIndex, int LocationSpeechOffset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCTFGame.GetLocationFor" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Pawn** )( params + 0 ) = StatusPawn;
				*( class Actor** )( params + 4 ) = LocationObject;
				*( int* )( params + 8 ) = MessageIndex;
				*( int* )( params + 12 ) = LocationSpeechOffset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				LocationObject = *( class Actor** )( params + 4 );
				MessageIndex = *( int* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RegisterFlag( class UTCarriedObject* F, int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCTFGame.RegisterFlag" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTCarriedObject** )( params + 0 ) = F;
				*( int* )( params + 4 ) = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool NearGoal( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCTFGame.NearGoal" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool WantFastSpawnFor( class AIController* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCTFGame.WantFastSpawnFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AIController** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckEndGame( class PlayerReplicationInfo* Winner, ScriptArray< wchar_t > Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCTFGame.CheckEndGame" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Winner;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ScoreFlag( class Controller* Scorer, class UTCTFFlag* theFlag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCTFGame.ScoreFlag" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = Scorer;
				*( class UTCTFFlag** )( params + 4 ) = theFlag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ViewObjective( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCTFGame.ViewObjective" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Actor* GetAutoObjectiveFor( class UTPlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTCTFGame.GetAutoObjectiveFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
