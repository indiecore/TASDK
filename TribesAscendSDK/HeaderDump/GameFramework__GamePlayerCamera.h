#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GamePlayerCamera." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GamePlayerCamera." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GamePlayerCamera." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GamePlayerCamera : public Camera
	{
	public:
			ADD_OBJECT( Actor, LastTargetBase )
			ADD_VAR( ::FloatProperty, SplitScreenShakeScale, 0xFFFFFFFF )
			ADD_OBJECT( Actor, LastViewTarget )
			ADD_VAR( ::FloatProperty, ForcedCamFOV, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bResetInterp, 0x4 )
			ADD_VAR( ::BoolProperty, bInterpolateCamChanges, 0x2 )
			ADD_VAR( ::BoolProperty, bUseForcedCamFOV, 0x1 )
			ADD_OBJECT( GameCameraBase, CurrentCamera )
			ADD_OBJECT( ScriptClass, FixedCameraClass )
			ADD_OBJECT( GameCameraBase, FixedCam )
			ADD_OBJECT( ScriptClass, ThirdPersonCameraClass )
			ADD_OBJECT( GameCameraBase, ThirdPersonCam )
			class GameCameraBase* CreateCamera( ScriptClass* CameraClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerCamera.CreateCamera" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = CameraClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GameCameraBase** )( params + function->return_val_offset() );
			}

			void CacheLastTargetBaseInfo( class Actor* TargetBase )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerCamera.CacheLastTargetBaseInfo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = TargetBase;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerCamera.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerCamera.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GameCameraBase* FindBestCameraType( class Actor* CameraTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerCamera.FindBestCameraType" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = CameraTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GameCameraBase** )( params + function->return_val_offset() );
			}

			bool ShouldConstrainAspectRatio(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerCamera.ShouldConstrainAspectRatio" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void UpdateViewTarget( void* &OutVT, float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerCamera.UpdateViewTarget" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( void** )params = OutVT;
				*( float* )( params + 44 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutVT = *( void** )params;
			}

			float AdjustFOVForViewport( float inHorizFOV, class Pawn* CameraTargetPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerCamera.AdjustFOVForViewport" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = inHorizFOV;
				*( class Pawn** )( params + 4 ) = CameraTargetPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void UpdateCameraLensEffects( void* &OutVT )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerCamera.UpdateCameraLensEffects" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( void** )params = OutVT;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutVT = *( void** )params;
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerCamera.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )params = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			void SetColorScale( Vector NewColorScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerCamera.SetColorScale" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = NewColorScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetInterpolation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerCamera.ResetInterpolation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessViewRotation( float DeltaTime, Rotator &out_ViewRotation, Rotator &out_DeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerCamera.ProcessViewRotation" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( float* )params = DeltaTime;
				*( Rotator* )( params + 4 ) = out_ViewRotation;
				*( Rotator* )( params + 16 ) = out_DeltaRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_ViewRotation = *( Rotator* )( params + 4 );
				out_DeltaRot = *( Rotator* )( params + 16 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
