#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameCrowdPopulationManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameCrowdPopulationManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameCrowdPopulationManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameCrowdPopulationManager : public CrowdPopulationManagerBase
	{
	public:
			ADD_OBJECT( GameCrowdAgent, QueryingAgent )
			ADD_OBJECT( NavigationHandle, NavigationHandle )
			ADD_OBJECT( ScriptClass, NavigationHandleClass )
			ADD_VAR( ::FloatProperty, InitialPopulationPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HeadVisibilityOffset, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, KilledCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PoolCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SpawnedCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinBehindSpawnDistSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxSpawnDistSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxSpawnDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PlayerPositionPredictionTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrioritizationUpdateIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrioritizationIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpawnPrioritizationInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AgentWarmupTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AgentCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxAgentPoolSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AgentFrequencySum, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Remainder, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SplitScreenNumReduction, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SpawnNum, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpawnRate, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWarmupPosition, 0x40 )
			ADD_VAR( ::BoolProperty, bHaveInitialPopulation, 0x20 )
			ADD_VAR( ::BoolProperty, bForceNavMeshPathing, 0x10 )
			ADD_VAR( ::BoolProperty, bForceObstacleChecking, 0x8 )
			ADD_VAR( ::BoolProperty, bCastShadows, 0x4 )
			ADD_VAR( ::BoolProperty, bEnableCrowdLightEnvironment, 0x2 )
			ADD_VAR( ::BoolProperty, bSpawningActive, 0x1 )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyPathChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.NotifyPathChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetMaxSpawnDist(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.GetMaxSpawnDist" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void AddSpawnPoint( class GameCrowdDestination* GCD )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.AddSpawnPoint" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdDestination** )params = GCD;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveSpawnPoint( class GameCrowdDestination* GCD )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.RemoveSpawnPoint" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdDestination** )params = GCD;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnGameCrowdPopulationManagerToggle( class SeqAct_GameCrowdPopulationManagerToggle* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.OnGameCrowdPopulationManagerToggle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_GameCrowdPopulationManagerToggle** )params = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FlushAgents(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.FlushAgents" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AgentDestroyed( class GameCrowdAgent* Agent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.AgentDestroyed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdAgent** )params = Agent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AddToAgentPool( class GameCrowdAgent* Agent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.AddToAgentPool" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdAgent** )params = Agent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )params = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			bool IsSpawningActive(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.IsSpawningActive" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Tick( float DeltaSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaSeconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GameCrowdDestination* PickSpawnPoint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.PickSpawnPoint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GameCrowdDestination** )( params + function->return_val_offset() );
			}

			void PrioritizeSpawnPoints( float DeltaSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.PrioritizeSpawnPoints" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaSeconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AnalyzeSpawnPoints( int StartIndex, int StopIndex, Vector ViewLocation, Vector PredictionLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.AnalyzeSpawnPoints" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( int* )params = StartIndex;
				*( int* )( params + 4 ) = StopIndex;
				*( Vector* )( params + 8 ) = ViewLocation;
				*( Vector* )( params + 20 ) = PredictionLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddPrioritizedSpawnPoint( class GameCrowdDestination* GCD, Vector ViewLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.AddPrioritizedSpawnPoint" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class GameCrowdDestination** )params = GCD;
				*( Vector* )( params + 4 ) = ViewLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ValidateSpawnAt( class GameCrowdDestination* Candidate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.ValidateSpawnAt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdDestination** )params = Candidate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class GameCrowdAgent* SpawnAgent( class GameCrowdDestination* SpawnLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.SpawnAgent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdDestination** )params = SpawnLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GameCrowdAgent** )( params + function->return_val_offset() );
			}

			class GameCrowdAgent* CreateNewAgent( class GameCrowdDestination* SpawnLoc, class GameCrowdAgent* AgentTemplate, class GameCrowdGroup* NewGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdPopulationManager.CreateNewAgent" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class GameCrowdDestination** )params = SpawnLoc;
				*( class GameCrowdAgent** )( params + 4 ) = AgentTemplate;
				*( class GameCrowdGroup** )( params + 8 ) = NewGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GameCrowdAgent** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
