#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrCamera_Spectator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrCamera_Spectator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrCamera_Spectator." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCamera_Spectator : public Camera
	{
	public:
			ADD_OBJECT( TrFlagBase, m_HiddenFlag )
			ADD_OBJECT( TrPawn, m_HiddenViewTargetPawn )
			ADD_VAR( ::BoolProperty, m_bViewFixed3p, 0x80 )
			ADD_VAR( ::BoolProperty, m_bViewTargetEyes, 0x40 )
			ADD_VAR( ::BoolProperty, m_bFastestPlayer, 0x20 )
			ADD_VAR( ::BoolProperty, m_bViewVehicles, 0x10 )
			ADD_VAR( ::BoolProperty, m_bViewFlags, 0x8 )
			ADD_VAR( ::BoolProperty, m_bViewFlagStands, 0x4 )
			ADD_VAR( ::BoolProperty, m_bViewGenerators, 0x2 )
			ADD_VAR( ::BoolProperty, m_bViewCameraBookmarks, 0x1 )
			ADD_VAR( ::FloatProperty, m_fMaxFixedViewCamDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_MinCamDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_MaxCamDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPawnZOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCameraDistanceInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInterpedCameraDistance, 0xFFFFFFFF )
			void InitializeFor( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCamera_Spectator.InitializeFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateCamera( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCamera_Spectator.UpdateCamera" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateViewTarget( void* &OutVT, float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCamera_Spectator.UpdateViewTarget" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( void** )params = OutVT;
				*( float* )( params + 44 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutVT = *( void** )params;
			}

			void ShowHiddenPawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCamera_Spectator.ShowHiddenPawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFOV( float NewFOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCamera_Spectator.SetFOV" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewFOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
