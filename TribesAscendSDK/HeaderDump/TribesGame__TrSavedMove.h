#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrSavedMove." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrSavedMove." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrSavedMove." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrSavedMove : public SavedMove
	{
	public:
			ADD_VAR( ::ByteProperty, m_CurrentDecelerationFactor, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bBlink, 0x8 )
			ADD_VAR( ::BoolProperty, m_bJumpJet, 0x4 )
			ADD_VAR( ::BoolProperty, m_bPressingJetpack, 0x2 )
			ADD_VAR( ::BoolProperty, m_bAirSpeedBoundToGroundSpeed, 0x1 )
			void Clear(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSavedMove.Clear" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostUpdate( class PlayerController* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSavedMove.PostUpdate" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanCombineWith( class SavedMove* NewMove, class Pawn* inPawn, float MaxDelta )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSavedMove.CanCombineWith" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class SavedMove** )( params + 0 ) = NewMove;
				*( class Pawn** )( params + 4 ) = inPawn;
				*( float* )( params + 8 ) = MaxDelta;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetMoveFor( class PlayerController* P, float DeltaTime, Vector newAccel, byte InDoubleClick )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSavedMove.SetMoveFor" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( class PlayerController** )( params + 0 ) = P;
				*( float* )( params + 4 ) = DeltaTime;
				*( Vector* )( params + 8 ) = newAccel;
				*( byte* )( params + 20 ) = InDoubleClick;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte CompressedFlags(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSavedMove.CompressedFlags" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte SetFlags( byte Flags, class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSavedMove.SetFlags" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = Flags;
				*( class PlayerController** )( params + 4 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetDebugString(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSavedMove.GetDebugString" );
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
