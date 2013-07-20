#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameCameraBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameCameraBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameCameraBase." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameCameraBase : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, bResetCameraInterpolation, 0x1 )
			ADD_OBJECT( GamePlayerCamera, PlayerCamera )
			void OnBecomeActive( class GameCameraBase* OldCamera )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCameraBase.OnBecomeActive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCameraBase** )params = OldCamera;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnBecomeInActive( class GameCameraBase* NewCamera )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCameraBase.OnBecomeInActive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCameraBase** )params = NewCamera;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetInterpolation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCameraBase.ResetInterpolation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateCamera( class Pawn* P, class GamePlayerCamera* CameraActor, float DeltaTime, void* &OutVT )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCameraBase.UpdateCamera" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( class Pawn** )params = P;
				*( class GamePlayerCamera** )( params + 4 ) = CameraActor;
				*( float* )( params + 8 ) = DeltaTime;
				*( void** )( params + 12 ) = OutVT;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutVT = *( void** )( params + 12 );
			}

			void ProcessViewRotation( float DeltaTime, class Actor* ViewTarget, Rotator &out_ViewRotation, Rotator &out_DeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCameraBase.ProcessViewRotation" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( float* )params = DeltaTime;
				*( class Actor** )( params + 4 ) = ViewTarget;
				*( Rotator* )( params + 8 ) = out_ViewRotation;
				*( Rotator* )( params + 20 ) = out_DeltaRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_ViewRotation = *( Rotator* )( params + 8 );
				out_DeltaRot = *( Rotator* )( params + 20 );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCameraBase.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )params = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			void Init(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCameraBase.Init" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ModifyPostProcessSettings( void* &PP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCameraBase.ModifyPostProcessSettings" );
				byte *params = ( byte* )( malloc( 220 ) );
				*( void** )params = PP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PP = *( void** )params;
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
