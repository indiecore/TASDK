#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrGame_TrCaH." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrGame_TrCaH." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrGame_TrCaH." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrGame_TrCaH : public TrGame
	{
	public:
			ADD_VAR( ::IntProperty, m_nPostCapturePointTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nTicketCountTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_5PointGoalScore, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_4PointGoalScore, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_3PointGoalScore, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nRemainingTicketTime, 0xFFFFFFFF )
			void PreBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.PreBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyServerSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.ApplyServerSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetTeam( class Controller* Other, class UTTeamInfo* NewTeam, bool bNewTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.SetTeam" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Controller** )params = Other;
				*( class UTTeamInfo** )( params + 4 ) = NewTeam;
				*( bool* )( params + 8 ) = bNewTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Logout( class Controller* Exiting )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.Logout" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = Exiting;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetLevel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.ResetLevel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ScoreKill( class Controller* Killer, class Controller* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.ScoreKill" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )params = Killer;
				*( class Controller** )( params + 4 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheckScore( class PlayerReplicationInfo* Scorer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.CheckScore" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = Scorer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GotoPendingRoundStartTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.GotoPendingRoundStartTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheckEndGame( class PlayerReplicationInfo* Winner, ScriptArray< wchar_t > Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.CheckEndGame" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerReplicationInfo** )params = Winner;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AwardPoint( byte TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.AwardPoint" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RestartPlayer( class Controller* NewPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.RestartPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = NewPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetGameTypeId(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.GetGameTypeId" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void OnCapturePointHeld( class TrCaHCapturePoint* HeldPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.OnCapturePointHeld" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrCaHCapturePoint** )params = HeldPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnCapturePointOwnershipChanged( class TrCaHCapturePoint* PointThatChanged, class TrPawn* TRP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.OnCapturePointOwnershipChanged" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrCaHCapturePoint** )params = PointThatChanged;
				*( class TrPawn** )( params + 4 ) = TRP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float RatePlayerStart( class PlayerStart* P, byte Team, class Controller* Player )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.RatePlayerStart" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( class PlayerStart** )params = P;
				*( byte* )( params + 4 ) = Team;
				*( class Controller** )( params + 8 ) = Player;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			class PlayerStart* ChoosePlayerStart( class Controller* Player, byte InTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCaH.ChoosePlayerStart" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class Controller** )params = Player;
				*( byte* )( params + 4 ) = InTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PlayerStart** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
