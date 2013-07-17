#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameCrowdAgentBehavior." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameCrowdAgentBehavior." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameCrowdAgentBehavior." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameCrowdAgentBehavior : public Object
	{
	public:
			bool AllowBehaviorAt( class GameCrowdDestination* Destination )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentBehavior.AllowBehaviorAt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdDestination** )( params + 0 ) = Destination;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AllowThisDestination( class GameCrowdDestination* Destination )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentBehavior.AllowThisDestination" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdDestination** )( params + 0 ) = Destination;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanBeUsedBy( class GameCrowdAgent* Agent, Vector CameraLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentBehavior.CanBeUsedBy" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class GameCrowdAgent** )( params + 0 ) = Agent;
				*( Vector* )( params + 4 ) = CameraLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( Actor, ActionTarget )
			ADD_VAR( ::FloatProperty, MaxPlayerDistance, 0xFFFFFFFF )
			class Actor* GetDestinationActor(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentBehavior.GetDestinationActor" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetBehaviorString(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentBehavior.GetBehaviorString" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( GameCrowdAgent, MyAgent )
			ADD_VAR( ::FloatProperty, TimeToStopPropagatingViralBehavior, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DurationOfViralBehaviorPropagation, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsPanicked, 0x10 )
			ADD_VAR( ::BoolProperty, bPassOnIsViralBehaviorFlag, 0x8 )
			ADD_VAR( ::BoolProperty, bIsViralBehavior, 0x4 )
			ADD_VAR( ::BoolProperty, bFaceActionTargetFirst, 0x2 )
			ADD_VAR( ::BoolProperty, bIdleBehavior, 0x1 )
			bool ShouldEndIdle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentBehavior.ShouldEndIdle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentBehavior.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FinishedTargetRotation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentBehavior.FinishedTargetRotation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool HandleMovement(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentBehavior.HandleMovement" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void InitBehavior( class GameCrowdAgent* Agent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentBehavior.InitBehavior" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdAgent** )( params + 0 ) = Agent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopBehavior(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentBehavior.StopBehavior" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnAnimEnd( class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentBehavior.OnAnimEnd" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class AnimNodeSequence** )( params + 0 ) = SeqNode;
				*( float* )( params + 4 ) = PlayedTime;
				*( float* )( params + 8 ) = ExcessTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangingDestination( class GameCrowdDestination* NewDest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentBehavior.ChangingDestination" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdDestination** )( params + 0 ) = NewDest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActivatedBy( class Actor* NewActionTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentBehavior.ActivatedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = NewActionTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PropagateViralBehaviorTo( class GameCrowdAgent* OtherAgent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentBehavior.PropagateViralBehaviorTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdAgent** )( params + 0 ) = OtherAgent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
