#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SavedMove." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SavedMove." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SavedMove." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SavedMove : public Object
	{
	public:
			byte SetFlags( byte Flags, class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SavedMove.SetFlags" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = Flags;
				*( class PlayerController** )( params + 4 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, TimeStamp, 0xFFFFFFFF )
			ADD_OBJECT( SavedMove, NextMove )
			ADD_STRUCT( ::VectorProperty, Acceleration, 0xFFFFFFFF )
			ADD_OBJECT( Actor, EndBase )
			ADD_STRUCT( ::VectorProperty, SavedRelativeLocation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, SavedLocation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, SavedVelocity, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForceRMVelocity, 0x20 )
			ADD_VAR( ::FloatProperty, Delta, 0xFFFFFFFF )
			byte CompressedFlags(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SavedMove.CompressedFlags" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool IsImportantMove( Vector CompareAccel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SavedMove.IsImportantMove" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = CompareAccel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::ByteProperty, DoubleClickMove, 0xFFFFFFFF )
			bool CanCombineWith( class SavedMove* NewMove, class Pawn* inPawn, float MaxDelta )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SavedMove.CanCombineWith" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class SavedMove** )( params + 0 ) = NewMove;
				*( class Pawn** )( params + 4 ) = inPawn;
				*( float* )( params + 8 ) = MaxDelta;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Vector GetStartLocation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SavedMove.GetStartLocation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			ADD_STRUCT( ::VectorProperty, StartVelocity, 0xFFFFFFFF )
			ADD_OBJECT( Actor, StartBase )
			ADD_STRUCT( ::VectorProperty, StartFloor, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, Rotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RootMotionInterpCurveLastValue, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RootMotionInterpCurrentTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AccelDotThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CustomTimeDilation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RMVelocity, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, StartRelativeLocation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, StartLocation, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RootMotionMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, SavedPhysics, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRootMotionFromInterpCurve, 0x80 )
			ADD_VAR( ::BoolProperty, bForceMaxAccel, 0x40 )
			ADD_VAR( ::BoolProperty, bPreciseDestination, 0x10 )
			ADD_VAR( ::BoolProperty, bDoubleJump, 0x8 )
			ADD_VAR( ::BoolProperty, bPressedJump, 0x4 )
			ADD_VAR( ::BoolProperty, bDuck, 0x2 )
			ADD_VAR( ::BoolProperty, bRun, 0x1 )
			void Clear(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SavedMove.Clear" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostUpdate( class PlayerController* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SavedMove.PostUpdate" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetInitialPosition( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SavedMove.SetInitialPosition" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMoveFor( class PlayerController* P, float DeltaTime, Vector newAccel, byte InDoubleClick )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SavedMove.SetMoveFor" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( class PlayerController** )( params + 0 ) = P;
				*( float* )( params + 4 ) = DeltaTime;
				*( Vector* )( params + 8 ) = newAccel;
				*( byte* )( params + 20 ) = InDoubleClick;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PrepMoveFor( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SavedMove.PrepMoveFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetMoveFor( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SavedMove.ResetMoveFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetDebugString(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SavedMove.GetDebugString" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
