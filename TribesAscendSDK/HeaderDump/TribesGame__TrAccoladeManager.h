#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrAccoladeManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrAccoladeManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrAccoladeManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrAccoladeManager : public Object
	{
	public:
			ADD_VAR( ::IntProperty, m_nLastFlagReturnTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nLastFlagGrabTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MAXIMUM_EMERGENCY_GRAB_DISTANCE, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MAXIMUM_FLAG_DEFENSE_DISTANCE, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MINIMUM_ULTRA_GRAB_SPEED, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MINIMUM_FAST_GRAB_SPEED, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MAXIMUM_LLAMA_GRAB_SPEED, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MINIMUM_TIME_FLAG_CREDITS, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nCurrSpinfusorKillStreak, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nCurrExplosiveKillStreak, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nCurrSnipingKillStreak, 0xFFFFFFFF )
			ADD_OBJECT( TrStatsInterface, Stats )
			ADD_OBJECT( TrPlayerController, m_TrPC )
			ADD_OBJECT( TrGame, m_TrG )
			int GetFlagDistance( Vector Loc1, Vector Loc2 )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.GetFlagDistance" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = Loc1;
				*( Vector* )( params + 12 ) = Loc2;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void Initialize( class TrPlayerController* TrPC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.Initialize" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )params = TrPC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetStreaks(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.ResetStreaks" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GiveAssist(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.GiveAssist" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GiveVehicleAssist(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.GiveVehicleAssist" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KillAsRabbit( class Controller* Killer, class Controller* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.KillAsRabbit" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )params = Killer;
				*( class Controller** )( params + 4 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KilledTheRabbit( class Controller* Killer, class Controller* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.KilledTheRabbit" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )params = Killer;
				*( class Controller** )( params + 4 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KilledTheFlagHolder(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.KilledTheFlagHolder" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateStandardKillingSpree( class UTPlayerReplicationInfo* Other, int currentSpree )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.UpdateStandardKillingSpree" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerReplicationInfo** )params = Other;
				*( int* )( params + 4 ) = currentSpree;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KilledGenerator(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.KilledGenerator" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RepairedBase(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.RepairedBase" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KilledBaseTurret(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.KilledBaseTurret" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KilledBaseRadar(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.KilledBaseRadar" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FlagGrab(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.FlagGrab" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FlagGrabDeathmatch(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.FlagGrabDeathmatch" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FlagHeld(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.FlagHeld" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FlagAssist( int AssistCount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.FlagAssist" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = AssistCount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FlagCapture( bool bUnAssisted )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.FlagCapture" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bUnAssisted;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FlagReturn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.FlagReturn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NoJoy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.NoJoy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GameCompleted(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.GameCompleted" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GameWon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.GameWon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateMultiKills( int MultiKillLevel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.UpdateMultiKills" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = MultiKillLevel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VehicleDestroyed( class TrVehicle* aVehicle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.VehicleDestroyed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrVehicle** )params = aVehicle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateSpecialAccolades( class Controller* Victim )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.UpdateSpecialAccolades" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = Victim;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void QueueAccolade( ScriptClass* Accolade, int ModifiedCredits )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.QueueAccolade" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = Accolade;
				*( int* )( params + 4 ) = ModifiedCredits;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CreditsGiven( ScriptClass* Accolade )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.CreditsGiven" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = Accolade;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void BroadcastAccolade( ScriptClass* Accolade )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAccoladeManager.BroadcastAccolade" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = Accolade;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
