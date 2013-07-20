#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameSpecialMove." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameSpecialMove." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameSpecialMove." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameSpecialMove : public Object
	{
	public:
			ADD_STRUCT( ::RotatorProperty, PreciseRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PreciseRotationInterpolationTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PreciseDestRelOffset, 0xFFFFFFFF )
			ADD_OBJECT( Actor, PreciseDestBase )
			ADD_STRUCT( ::VectorProperty, PreciseDestination, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForcePrecisePosition, 0x20 )
			ADD_VAR( ::BoolProperty, bReachedPreciseRotation, 0x10 )
			ADD_VAR( ::BoolProperty, bReachPreciseRotation, 0x8 )
			ADD_VAR( ::BoolProperty, bReachedPreciseDestination, 0x4 )
			ADD_VAR( ::BoolProperty, bReachPreciseDestination, 0x2 )
			ADD_VAR( ::BoolProperty, bLastCanDoSpecialMove, 0x1 )
			ADD_VAR( ::FloatProperty, LastCanDoSpecialMoveTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, Handle, 0xFFFFFFFF )
			ADD_OBJECT( GamePawn, PawnOwner )
			void InitSpecialMove( class GamePawn* inPawn, ScriptName InHandle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.InitSpecialMove" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class GamePawn** )params = inPawn;
				*( ScriptName* )( params + 4 ) = InHandle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitSpecialMoveFlags( int &out_Flags )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.InitSpecialMoveFlags" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = out_Flags;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Flags = *( int* )params;
			}

			void ExtractSpecialMoveFlags( int Flags )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.ExtractSpecialMoveFlags" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Flags;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanChainMove( ScriptName NextMove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.CanChainMove" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NextMove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanOverrideMoveWith( ScriptName NewMove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.CanOverrideMoveWith" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewMove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanOverrideSpecialMove( ScriptName InMove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.CanOverrideSpecialMove" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = InMove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanDoSpecialMove( bool bForceCheck )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.CanDoSpecialMove" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bForceCheck;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool InternalCanDoSpecialMove(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.InternalCanDoSpecialMove" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SpecialMoveStarted( bool bForced, ScriptName PrevMove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.SpecialMoveStarted" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( bool* )params = bForced;
				*( ScriptName* )( params + 4 ) = PrevMove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpecialMoveEnded( ScriptName PrevMove, ScriptName NextMove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.SpecialMoveEnded" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )params = PrevMove;
				*( ScriptName* )( params + 8 ) = NextMove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpecialMoveFlagsUpdated(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.SpecialMoveFlagsUpdated" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldReplicate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.ShouldReplicate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetReachPreciseDestination( Vector DestinationToReach, bool bCancel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.SetReachPreciseDestination" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = DestinationToReach;
				*( bool* )( params + 12 ) = bCancel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFacePreciseRotation( Rotator RotationToFace, float InterpolationTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.SetFacePreciseRotation" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )params = RotationToFace;
				*( float* )( params + 12 ) = InterpolationTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReachedPrecisePosition(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.ReachedPrecisePosition" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetFacePreciseRotation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.ResetFacePreciseRotation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool MessageEvent( ScriptName EventName, class Object* Sender )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.MessageEvent" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = EventName;
				*( class Object** )( params + 8 ) = Sender;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ForcePawnRotation( class Pawn* P, Rotator NewRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.ForcePawnRotation" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Pawn** )params = P;
				*( Rotator* )( params + 4 ) = NewRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector WorldToRelativeOffset( Rotator InRotation, Vector WorldSpaceOffset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.WorldToRelativeOffset" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Rotator* )params = InRotation;
				*( Vector* )( params + 12 ) = WorldSpaceOffset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector RelativeToWorldOffset( Rotator InRotation, Vector RelativeSpaceOffset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameSpecialMove.RelativeToWorldOffset" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Rotator* )params = InRotation;
				*( Vector* )( params + 12 ) = RelativeSpaceOffset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
