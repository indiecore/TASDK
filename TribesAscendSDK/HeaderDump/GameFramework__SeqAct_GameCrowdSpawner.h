#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.SeqAct_GameCrowdSpawner." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.SeqAct_GameCrowdSpawner." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.SeqAct_GameCrowdSpawner." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_GameCrowdSpawner : public SeqAct_Latent
	{
	public:
			ADD_VAR( ::FloatProperty, AgentWarmupTime, 0xFFFFFFFF )
			ADD_OBJECT( GameCrowdReplicationActor, RepActor )
			ADD_OBJECT( GameCrowd_ListOfAgents, CrowdAgentList )
			ADD_VAR( ::FloatProperty, AgentFrequencySum, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Remainder, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SplitScreenNumReduction, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpawnRadius, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SpawnNum, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpawnRate, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastSpawnLocIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NextDestinationIndex, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCastShadows, 0x200 )
			ADD_VAR( ::BoolProperty, bWarmupPosition, 0x100 )
			ADD_VAR( ::BoolProperty, bOnlySpawnHidden, 0x80 )
			ADD_VAR( ::BoolProperty, bForceNavMeshPathing, 0x40 )
			ADD_VAR( ::BoolProperty, bForceObstacleChecking, 0x20 )
			ADD_VAR( ::BoolProperty, bEnableCrowdLightEnvironment, 0x10 )
			ADD_VAR( ::BoolProperty, bHasReducedNumberDueToSplitScreen, 0x8 )
			ADD_VAR( ::BoolProperty, bRespawnDeadAgents, 0x4 )
			ADD_VAR( ::BoolProperty, bCycleSpawnLocs, 0x2 )
			ADD_VAR( ::BoolProperty, bSpawningActive, 0x1 )
			void SpawnedAgent( class GameCrowdAgent* NewAgent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.SeqAct_GameCrowdSpawner.SpawnedAgent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdAgent** )( params + 0 ) = NewAgent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CacheSpawnerVars(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.SeqAct_GameCrowdSpawner.CacheSpawnerVars" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KillAgents(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.SeqAct_GameCrowdSpawner.KillAgents" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateSpawning( float DeltaSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.SeqAct_GameCrowdSpawner.UpdateSpawning" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaSeconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GameCrowdAgent* SpawnAgent( class Actor* SpawnLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.SeqAct_GameCrowdSpawner.SpawnAgent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = SpawnLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GameCrowdAgent** )( params + function->return_val_offset() );
			}

			class GameCrowdAgent* CreateNewAgent( class Actor* SpawnLoc, class GameCrowdAgent* AgentTemplate, class GameCrowdGroup* NewGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.SeqAct_GameCrowdSpawner.CreateNewAgent" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Actor** )( params + 0 ) = SpawnLoc;
				*( class GameCrowdAgent** )( params + 4 ) = AgentTemplate;
				*( class GameCrowdGroup** )( params + 8 ) = NewGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GameCrowdAgent** )( params + function->return_val_offset() );
			}

			int GetObjClassVersion(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.SeqAct_GameCrowdSpawner.GetObjClassVersion" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
