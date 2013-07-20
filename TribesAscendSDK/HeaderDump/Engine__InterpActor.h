#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.InterpActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.InterpActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.InterpActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class InterpActor : public DynamicSMActor
	{
	public:
			ADD_VAR( ::BoolProperty, bMonitorMover, 0x2 )
			ADD_OBJECT( NavigationPoint, MyMarker )
			ADD_OBJECT( SoundCue, ClosedSound )
			ADD_OBJECT( SoundCue, ClosingAmbientSound )
			ADD_OBJECT( SoundCue, CloseSound )
			ADD_OBJECT( SoundCue, OpenedSound )
			ADD_OBJECT( SoundCue, OpeningAmbientSound )
			ADD_OBJECT( SoundCue, OpenSound )
			ADD_VAR( ::FloatProperty, StayOpenTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxZVelocity, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsLift, 0x80 )
			ADD_VAR( ::BoolProperty, bShouldShadowParentAllAttachedActors, 0x40 )
			ADD_VAR( ::BoolProperty, bStopOnEncroach, 0x20 )
			ADD_VAR( ::BoolProperty, bContinueOnEncroachPhysicsObject, 0x10 )
			ADD_VAR( ::BoolProperty, bDestroyProjectilesOnEncroach, 0x8 )
			ADD_VAR( ::BoolProperty, bMonitorZVelocity, 0x4 )
			ADD_VAR( ::BoolProperty, bShouldSaveForCheckpoint, 0x1 )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetShadowParentOnAllAttachedComponents(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.SetShadowParentOnAllAttachedComponents" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool EncroachingOn( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.EncroachingOn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RanInto( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.RanInto" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Attach( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.Attach" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Detach( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.Detach" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Restart(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.Restart" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FinishedOpen(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.FinishedOpen" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayMovingSound( bool bClosing )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.PlayMovingSound" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bClosing;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InterpolationStarted( class SeqAct_Interp* InterpAction, class InterpGroupInst* GroupInst )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.InterpolationStarted" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class SeqAct_Interp** )params = InterpAction;
				*( class InterpGroupInst** )( params + 4 ) = GroupInst;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InterpolationFinished( class SeqAct_Interp* InterpAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.InterpolationFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Interp** )params = InterpAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InterpolationChanged( class SeqAct_Interp* InterpAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.InterpolationChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Interp** )params = InterpAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.ShutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldSaveForCheckpoint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.ShouldSaveForCheckpoint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CreateCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.CreateCheckpointRecord" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( void** )params = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )params;
			}

			void ApplyCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InterpActor.ApplyCheckpointRecord" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( void** )params = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )params;
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
