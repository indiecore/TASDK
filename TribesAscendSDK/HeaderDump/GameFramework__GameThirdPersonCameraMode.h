#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameThirdPersonCameraMode." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameThirdPersonCameraMode." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameThirdPersonCameraMode." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameThirdPersonCameraMode : public Object
	{
	public:
			ADD_OBJECT( GameThirdPersonCamera, ThirdPersonCam )
			float GetDesiredFOV( class Pawn* ViewedPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCameraMode.GetDesiredFOV" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = ViewedPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool SetFocusPoint( class Pawn* ViewedPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCameraMode.SetFocusPoint" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = ViewedPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::ByteProperty, CurrentViewportType, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OffsetAdjustmentInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewOffsetInterp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DOF_RadiusFalloff, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, DOFTraceExtent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DOFDistanceInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastDOFDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastDOFRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DOF_MaxFarBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DOF_MaxNearBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DOF_FocusInnerRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DOF_BlurKernelSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DOF_FalloffExponent, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, TargetRelativeCameraOriginOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, WorstLocOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastRunOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RunOffsetInterpSpeedOut, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RunOffsetInterpSpeedIn, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RunOffsetScalingThreshold, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RunBackAdjustment, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RunFwdAdjustment, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastStrafeOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StrafeOffsetInterpSpeedOut, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StrafeOffsetInterpSpeedIn, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StrafeOffsetScalingThreshold, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, StrafeRightAdjustment, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, StrafeLeftAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OriginRotInterpSpeed, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PerAxisOriginLocInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OriginLocInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FollowingCameraVelThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FollowingInterpSpeed_Roll, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FollowingInterpSpeed_Yaw, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FollowingInterpSpeed_Pitch, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bInterpViewOffsetOnlyForCamTransition, 0x8000 )
			ADD_VAR( ::BoolProperty, bNoFOVPostProcess, 0x4000 )
			ADD_VAR( ::BoolProperty, bDOFUpdated, 0x2000 )
			ADD_VAR( ::BoolProperty, bAdjustDOF, 0x1000 )
			ADD_VAR( ::BoolProperty, bApplyDeltaViewOffset, 0x800 )
			ADD_VAR( ::BoolProperty, bSmoothViewOffsetPitchChanges, 0x400 )
			ADD_VAR( ::BoolProperty, bSkipCameraCollision, 0x200 )
			ADD_VAR( ::BoolProperty, bValidateWorstLoc, 0x100 )
			ADD_VAR( ::BoolProperty, bDoPredictiveAvoidance, 0x80 )
			ADD_VAR( ::BoolProperty, bRotInterpSpeedConstant, 0x40 )
			ADD_VAR( ::BoolProperty, bInterpRotation, 0x20 )
			ADD_VAR( ::BoolProperty, bUsePerAxisOriginLocInterp, 0x10 )
			ADD_VAR( ::BoolProperty, bInterpLocation, 0x8 )
			ADD_VAR( ::BoolProperty, bFollowTarget, 0x4 )
			ADD_VAR( ::BoolProperty, bDirectLook, 0x2 )
			ADD_VAR( ::BoolProperty, bLockedToViewTarget, 0x1 )
			ADD_VAR( ::FloatProperty, BlendTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FOVAngle, 0xFFFFFFFF )
			void Init(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCameraMode.Init" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnBecomeActive( class Pawn* TargetPawn, class GameThirdPersonCameraMode* PrevMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCameraMode.OnBecomeActive" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )( params + 0 ) = TargetPawn;
				*( class GameThirdPersonCameraMode** )( params + 4 ) = PrevMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnBecomeInActive( class Pawn* TargetPawn, class GameThirdPersonCameraMode* NewMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCameraMode.OnBecomeInActive" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )( params + 0 ) = TargetPawn;
				*( class GameThirdPersonCameraMode** )( params + 4 ) = NewMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector AdjustViewOffset( class Pawn* P, Vector Offset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCameraMode.AdjustViewOffset" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Pawn** )( params + 0 ) = P;
				*( Vector* )( params + 4 ) = Offset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector GetCameraWorstCaseLoc( class Pawn* TargetPawn, void* CurrentViewTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCameraMode.GetCameraWorstCaseLoc" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( class Pawn** )( params + 0 ) = TargetPawn;
				*( void** )( params + 4 ) = CurrentViewTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void ProcessViewRotation( float DeltaTime, class Actor* ViewTarget, Rotator &out_ViewRotation, Rotator &out_DeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCameraMode.ProcessViewRotation" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( float* )( params + 0 ) = DeltaTime;
				*( class Actor** )( params + 4 ) = ViewTarget;
				*( Rotator* )( params + 8 ) = out_ViewRotation;
				*( Rotator* )( params + 20 ) = out_DeltaRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_ViewRotation = *( Rotator* )( params + 8 );
				out_DeltaRot = *( Rotator* )( params + 20 );
			}

			Vector GetDOFFocusLoc( class Actor* TraceOwner, Vector StartTrace, Vector EndTrace )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCameraMode.GetDOFFocusLoc" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Actor** )( params + 0 ) = TraceOwner;
				*( Vector* )( params + 4 ) = StartTrace;
				*( Vector* )( params + 16 ) = EndTrace;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector DOFTrace( class Actor* TraceOwner, Vector StartTrace, Vector EndTrace )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCameraMode.DOFTrace" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Actor** )( params + 0 ) = TraceOwner;
				*( Vector* )( params + 4 ) = StartTrace;
				*( Vector* )( params + 16 ) = EndTrace;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void UpdatePostProcess( void* &VT, float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCameraMode.UpdatePostProcess" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( void** )( params + 0 ) = VT;
				*( float* )( params + 44 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				VT = *( void** )( params + 0 );
			}

			void ModifyPostProcessSettings( void* &PP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCameraMode.ModifyPostProcessSettings" );
				byte *params = ( byte* )( malloc( 220 ) );
				*( void** )( params + 0 ) = PP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PP = *( void** )( params + 0 );
			}

			void SetViewOffset( void* &NewViewOffset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCameraMode.SetViewOffset" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 0 ) = NewViewOffset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				NewViewOffset = *( void** )( params + 0 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
