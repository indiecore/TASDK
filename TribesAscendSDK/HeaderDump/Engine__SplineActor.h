#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SplineActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SplineActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SplineActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SplineActor : public Actor
	{
	public:
			ADD_VAR( ::IntProperty, visitedWeight, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, bestPathWeight, 0xFFFFFFFF )
			ADD_OBJECT( SplineActor, previousPath )
			ADD_OBJECT( SplineActor, prevOrdered )
			ADD_OBJECT( SplineActor, nextOrdered )
			ADD_VAR( ::BoolProperty, bAlreadyVisited, 0x2 )
			ADD_VAR( ::BoolProperty, bDisableDestination, 0x1 )
			ADD_STRUCT( ::VectorProperty, SplineActorTangent, 0xFFFFFFFF )
			Vector GetWorldSpaceTangent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.GetWorldSpaceTangent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void UpdateSplineComponents(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.UpdateSplineComponents" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateConnectedSplineComponents( bool bFinish )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.UpdateConnectedSplineComponents" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bFinish;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddConnectionTo( class SplineActor* NextActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.AddConnectionTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SplineActor** )params = NextActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsConnectedTo( class SplineActor* NextActor, bool bCheckForDisableDestination )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.IsConnectedTo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class SplineActor** )params = NextActor;
				*( bool* )( params + 4 ) = bCheckForDisableDestination;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void* FindSplineComponentTo( class SplineActor* NextActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.FindSplineComponentTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SplineActor** )params = NextActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			class SplineActor* FindTargetForComponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.FindTargetForComponent" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SplineActor** )( params + function->return_val_offset() );
			}

			void BreakConnectionTo( class SplineActor* NextActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.BreakConnectionTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SplineActor** )params = NextActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BreakAllConnections(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.BreakAllConnections" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BreakAllConnectionsFrom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.BreakAllConnectionsFrom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class SplineActor* GetRandomConnection( bool bUseLinksFrom )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.GetRandomConnection" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bUseLinksFrom;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SplineActor** )( params + function->return_val_offset() );
			}

			class SplineActor* GetBestConnectionInDirection( Vector DesiredDir, bool bUseLinksFrom )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.GetBestConnectionInDirection" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = DesiredDir;
				*( bool* )( params + 12 ) = bUseLinksFrom;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SplineActor** )( params + function->return_val_offset() );
			}

			bool FindSplinePathTo( class SplineActor* Goal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.FindSplinePathTo" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class SplineActor** )params = Goal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetAllConnectedSplineActors(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.GetAllConnectedSplineActors" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnToggle( class SeqAct_Toggle* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.OnToggle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Toggle** )params = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnToggleHidden( class SeqAct_ToggleHidden* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SplineActor.OnToggleHidden" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ToggleHidden** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
