#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.GameplayEventsWriter." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.GameplayEventsWriter." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.GameplayEventsWriter." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameplayEventsWriter : public GameplayEvents
	{
	public:
			ADD_OBJECT( GameInfo, Game )
			int ResolvePlayerIndex( class Controller* Player )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.ResolvePlayerIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = Player;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void StartLogging( float HeartbeatDelta )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.StartLogging" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = HeartbeatDelta;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetLogging( float HeartbeatDelta )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.ResetLogging" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = HeartbeatDelta;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndLogging(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.EndLogging" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsSessionInProgress(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.IsSessionInProgress" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool OpenStatsFile( ScriptArray< wchar_t > Filename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.OpenStatsFile" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Filename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CloseStatsFile(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.CloseStatsFile" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SerializeHeader(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.SerializeHeader" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SerializeFooter(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.SerializeFooter" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Poll(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.Poll" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetGameTypeId(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.GetGameTypeId" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void LogGameIntEvent( int EventID, int Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogGameIntEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = EventID;
				*( int* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogGameStringEvent( int EventID, ScriptArray< wchar_t > Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogGameStringEvent" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = EventID;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogGameFloatEvent( int EventID, float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogGameFloatEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = EventID;
				*( float* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogGamePositionEvent( int EventID, Vector &Position, float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogGamePositionEvent" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )( params + 0 ) = EventID;
				*( Vector* )( params + 4 ) = Position;
				*( float* )( params + 16 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Position = *( Vector* )( params + 4 );
			}

			void LogTeamIntEvent( int EventID, class TeamInfo* Team, int Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogTeamIntEvent" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = EventID;
				*( class TeamInfo** )( params + 4 ) = Team;
				*( int* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogTeamFloatEvent( int EventID, class TeamInfo* Team, float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogTeamFloatEvent" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = EventID;
				*( class TeamInfo** )( params + 4 ) = Team;
				*( float* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogTeamStringEvent( int EventID, class TeamInfo* Team, ScriptArray< wchar_t > Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogTeamStringEvent" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )( params + 0 ) = EventID;
				*( class TeamInfo** )( params + 4 ) = Team;
				*( ScriptArray< wchar_t >* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogPlayerIntEvent( int EventID, class Controller* Player, int Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogPlayerIntEvent" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = EventID;
				*( class Controller** )( params + 4 ) = Player;
				*( int* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogPlayerFloatEvent( int EventID, class Controller* Player, float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogPlayerFloatEvent" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = EventID;
				*( class Controller** )( params + 4 ) = Player;
				*( float* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogPlayerStringEvent( int EventID, class Controller* Player, ScriptArray< wchar_t > EventString )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogPlayerStringEvent" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )( params + 0 ) = EventID;
				*( class Controller** )( params + 4 ) = Player;
				*( ScriptArray< wchar_t >* )( params + 8 ) = EventString;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogPlayerSpawnEvent( int EventID, class Controller* Player, ScriptClass* PawnClass, int TeamID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogPlayerSpawnEvent" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = EventID;
				*( class Controller** )( params + 4 ) = Player;
				*( ScriptClass** )( params + 8 ) = PawnClass;
				*( int* )( params + 12 ) = TeamID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogPlayerLoginChange( int EventID, class Controller* Player, ScriptArray< wchar_t > PlayerName, void* PlayerID, bool bSplitScreen )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogPlayerLoginChange" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( int* )( params + 0 ) = EventID;
				*( class Controller** )( params + 4 ) = Player;
				*( ScriptArray< wchar_t >* )( params + 8 ) = PlayerName;
				*( void** )( params + 20 ) = PlayerID;
				*( bool* )( params + 28 ) = bSplitScreen;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogAllPlayerPositionsEvent( int EventID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogAllPlayerPositionsEvent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = EventID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogPlayerKillDeath( int EventID, int KillType, class Controller* Killer, ScriptClass* dmgType, class Controller* Dead )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogPlayerKillDeath" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )( params + 0 ) = EventID;
				*( int* )( params + 4 ) = KillType;
				*( class Controller** )( params + 8 ) = Killer;
				*( ScriptClass** )( params + 12 ) = dmgType;
				*( class Controller** )( params + 16 ) = Dead;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogPlayerPlayerEvent( int EventID, class Controller* Player, class Controller* Target )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogPlayerPlayerEvent" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = EventID;
				*( class Controller** )( params + 4 ) = Player;
				*( class Controller** )( params + 8 ) = Target;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogWeaponIntEvent( int EventID, class Controller* Player, ScriptClass* WeaponClass, int Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogWeaponIntEvent" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = EventID;
				*( class Controller** )( params + 4 ) = Player;
				*( ScriptClass** )( params + 8 ) = WeaponClass;
				*( int* )( params + 12 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogDamageEvent( int EventID, class Controller* Player, ScriptClass* dmgType, class Controller* Target, int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogDamageEvent" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )( params + 0 ) = EventID;
				*( class Controller** )( params + 4 ) = Player;
				*( ScriptClass** )( params + 8 ) = dmgType;
				*( class Controller** )( params + 12 ) = Target;
				*( int* )( params + 16 ) = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogProjectileIntEvent( int EventID, class Controller* Player, ScriptClass* Proj, int Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogProjectileIntEvent" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = EventID;
				*( class Controller** )( params + 4 ) = Player;
				*( ScriptClass** )( params + 8 ) = Proj;
				*( int* )( params + 12 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogSystemPollEvents(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.LogSystemPollEvents" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GenericParamListStatEntry* GetGenericParamListEntry(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.GetGenericParamListEntry" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GenericParamListStatEntry** )( params + function->return_val_offset() );
			}

			void RecordAIPathFail( class Controller* AI, ScriptArray< wchar_t > Reason, Vector Dest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.RecordAIPathFail" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Controller** )( params + 0 ) = AI;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Reason;
				*( Vector* )( params + 16 ) = Dest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int RecordCoverLinkFireLinks( class CoverLink* Link, class Controller* Player )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameplayEventsWriter.RecordCoverLinkFireLinks" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class CoverLink** )( params + 0 ) = Link;
				*( class Controller** )( params + 4 ) = Player;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
