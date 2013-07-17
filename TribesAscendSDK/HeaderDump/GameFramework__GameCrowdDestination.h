#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameCrowdDestination." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameCrowdDestination." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameCrowdDestination." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameCrowdDestination : public GameCrowdInteractionPoint
	{
	public:
			ADD_OBJECT( GameCrowdPopulationManager, MyPopMgr )
			ADD_VAR( ::FloatProperty, LastSpawnTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Priority, 0xFFFFFFFF )
			ADD_OBJECT( GameCrowdAgent, AgentEnRoute )
			ADD_VAR( ::FloatProperty, SpawnRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InteractionDelay, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, InteractionTag, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExactReachTolerance, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CustomerCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Frequency, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Capacity, 0xFFFFFFFF )
			ADD_OBJECT( GameCrowdDestinationQueuePoint, QueueHead )
			ADD_VAR( ::BoolProperty, bHasNavigationMesh, 0x20000 )
			ADD_VAR( ::BoolProperty, bAdjacentToVisibleNode, 0x10000 )
			ADD_VAR( ::BoolProperty, bIsBeyondSpawnDistance, 0x8000 )
			ADD_VAR( ::BoolProperty, bCanSpawnHereNow, 0x4000 )
			ADD_VAR( ::BoolProperty, bWillBeVisible, 0x2000 )
			ADD_VAR( ::BoolProperty, bIsVisible, 0x1000 )
			ADD_VAR( ::BoolProperty, bSoftPerimeter, 0x800 )
			ADD_VAR( ::BoolProperty, bSpawnAtEdge, 0x400 )
			ADD_VAR( ::BoolProperty, bLineSpawner, 0x200 )
			ADD_VAR( ::BoolProperty, bAllowsSpawning, 0x100 )
			ADD_VAR( ::BoolProperty, bHasRestrictions, 0x80 )
			ADD_VAR( ::BoolProperty, bMustReachExactly, 0x40 )
			ADD_VAR( ::BoolProperty, bFleeDestination, 0x20 )
			ADD_VAR( ::BoolProperty, bSkipBehaviorIfPanicked, 0x10 )
			ADD_VAR( ::BoolProperty, bAvoidWhenPanicked, 0x8 )
			ADD_VAR( ::BoolProperty, bLastAllowableResult, 0x4 )
			ADD_VAR( ::BoolProperty, bAllowAsPreviousDestination, 0x2 )
			ADD_VAR( ::BoolProperty, bKillWhenReached, 0x1 )
			bool ReachedByAgent( class GameCrowdAgent* Agent, Vector TestPosition, bool bTestExactly )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestination.ReachedByAgent" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class GameCrowdAgent** )( params + 0 ) = Agent;
				*( Vector* )( params + 4 ) = TestPosition;
				*( bool* )( params + 16 ) = bTestExactly;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestination.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestination.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReachedDestination( class GameCrowdAgent* Agent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestination.ReachedDestination" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdAgent** )( params + 0 ) = Agent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PickNewDestinationFor( class GameCrowdAgent* Agent, bool bIgnoreRestrictions )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestination.PickNewDestinationFor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class GameCrowdAgent** )( params + 0 ) = Agent;
				*( bool* )( params + 4 ) = bIgnoreRestrictions;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowableDestinationFor( class GameCrowdAgent* Agent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestination.AllowableDestinationFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdAgent** )( params + 0 ) = Agent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DecrementCustomerCount( class GameCrowdAgent* DepartingAgent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestination.DecrementCustomerCount" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdAgent** )( params + 0 ) = DepartingAgent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IncrementCustomerCount( class GameCrowdAgent* ArrivingAgent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestination.IncrementCustomerCount" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdAgent** )( params + 0 ) = ArrivingAgent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AtCapacity(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestination.AtCapacity" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetSpawnPosition( class SeqAct_GameCrowdSpawner* Spawner, Vector &SpawnPos, Rotator &SpawnRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestination.GetSpawnPosition" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class SeqAct_GameCrowdSpawner** )( params + 0 ) = Spawner;
				*( Vector* )( params + 4 ) = SpawnPos;
				*( Rotator* )( params + 16 ) = SpawnRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				SpawnPos = *( Vector* )( params + 4 );
				SpawnRot = *( Rotator* )( params + 16 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
