#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameCrowdDestinationQueuePoint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameCrowdDestinationQueuePoint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameCrowdDestinationQueuePoint." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameCrowdDestinationQueuePoint : public GameCrowdInteractionPoint
	{
	public:
			ADD_OBJECT( GameCrowdAgent, QueuedAgent )
			ADD_OBJECT( GameCrowdDestinationQueuePoint, NextQueuePosition )
			bool HasCustomer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestinationQueuePoint.HasCustomer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bPendingAdvance, 0x2 )
			bool HasSpace(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestinationQueuePoint.HasSpace" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( ScriptClass, QueueBehaviorClass )
			ADD_VAR( ::FloatProperty, AverageReactionTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bClearingQueue, 0x1 )
			ADD_OBJECT( GameCrowdDestination, QueueDestination )
			ADD_OBJECT( GameCrowdInteractionPoint, PreviousQueuePosition )
			bool QueueReachedBy( class GameCrowdAgent* Agent, Vector TestPosition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestinationQueuePoint.QueueReachedBy" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class GameCrowdAgent** )params = Agent;
				*( Vector* )( params + 4 ) = TestPosition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ReachedDestination( class GameCrowdAgent* Agent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestinationQueuePoint.ReachedDestination" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdAgent** )params = Agent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdvanceCustomerTo( class GameCrowdInteractionPoint* FrontPosition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestinationQueuePoint.AdvanceCustomerTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdInteractionPoint** )params = FrontPosition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActuallyAdvance(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestinationQueuePoint.ActuallyAdvance" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddCustomer( class GameCrowdAgent* NewCustomer, class GameCrowdInteractionPoint* PreviousPosition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestinationQueuePoint.AddCustomer" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class GameCrowdAgent** )params = NewCustomer;
				*( class GameCrowdInteractionPoint** )( params + 4 ) = PreviousPosition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearQueue( class GameCrowdAgent* OldCustomer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdDestinationQueuePoint.ClearQueue" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdAgent** )params = OldCustomer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
