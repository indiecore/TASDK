#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameThirdPersonCamera." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameThirdPersonCamera." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameThirdPersonCamera." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameThirdPersonCamera : public GameCameraBase
	{
	public:
			ADD_STRUCT( ::VectorProperty, LastOffsetAdjustment, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, LastPreModifierCameraRot, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastPreModifierCameraLoc, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastWorstLocationLocal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WorstLocInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DirectLookInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DirectLookYaw, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastPostCamTurnYaw, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TurnDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TurnTotalTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TurnEndAngle, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TurnStartAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TurnCurTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDebugChangedCameraMode, 0x40 )
			ADD_VAR( ::BoolProperty, bDoingDirectLook, 0x20 )
			ADD_VAR( ::BoolProperty, bDrawDebug, 0x10 )
			ADD_VAR( ::BoolProperty, bTurnAlignTargetWhenFinished, 0x8 )
			ADD_VAR( ::BoolProperty, bDoingACameraTurn, 0x4 )
			ADD_VAR( ::BoolProperty, bFocusPointSuccessful, 0x2 )
			ADD_VAR( ::BoolProperty, bFocusPointSet, 0x1 )
			ADD_STRUCT( ::VectorProperty, LastFocusPointLoc, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ActualFocusPointWorldLoc, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastFocusChangeTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Focus_FastAdjustKickInTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Focus_MaxTries, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Focus_StepHeightAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Focus_BackOffStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LeftoverPitchAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastYawAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastPitchAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastHeightAdjustment, 0xFFFFFFFF )
			ADD_OBJECT( GameThirdPersonCameraMode, CurrentCamMode )
			ADD_OBJECT( ScriptClass, ThirdPersonCamDefaultClass )
			ADD_OBJECT( GameThirdPersonCameraMode, ThirdPersonCamDefault )
			ADD_VAR( ::FloatProperty, LastCamFOV, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastViewOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OriginOffsetInterpSpeed, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, LastActualCameraOriginRot, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastActualOriginOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PenetrationExtentScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PenetrationBlockedPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PenetrationBlendInTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PenetrationBlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WorstLocPenetrationExtentScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WorstLocBlockedPct, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastActualCameraOrigin, 0xFFFFFFFF )
			class GameThirdPersonCameraMode* CreateCameraMode( ScriptClass* ModeClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.CreateCameraMode" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = ModeClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GameThirdPersonCameraMode** )( params + function->return_val_offset() );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Init(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.Init" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetDesiredFOV( class Pawn* ViewedPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.GetDesiredFOV" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = ViewedPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void UpdateCamera( class Pawn* P, class GamePlayerCamera* CameraActor, float DeltaTime, void* &OutVT )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.UpdateCamera" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( class Pawn** )( params + 0 ) = P;
				*( class GamePlayerCamera** )( params + 4 ) = CameraActor;
				*( float* )( params + 8 ) = DeltaTime;
				*( void** )( params + 12 ) = OutVT;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutVT = *( void** )( params + 12 );
			}

			void UpdateCameraMode( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.UpdateCameraMode" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayerUpdateCamera( class Pawn* P, class GamePlayerCamera* CameraActor, float DeltaTime, void* &OutVT )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.PlayerUpdateCamera" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( class Pawn** )( params + 0 ) = P;
				*( class GamePlayerCamera** )( params + 4 ) = CameraActor;
				*( float* )( params + 8 ) = DeltaTime;
				*( void** )( params + 12 ) = OutVT;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutVT = *( void** )( params + 12 );
			}

			void BeginTurn( int StartAngle, int EndAngle, float TimeSec, float DelaySec, bool bAlignTargetWhenFinished )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.BeginTurn" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )( params + 0 ) = StartAngle;
				*( int* )( params + 4 ) = EndAngle;
				*( float* )( params + 8 ) = TimeSec;
				*( float* )( params + 12 ) = DelaySec;
				*( bool* )( params + 16 ) = bAlignTargetWhenFinished;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndTurn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.EndTurn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdjustTurn( int AngleOffset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.AdjustTurn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = AngleOffset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFocusOnLoc( Vector FocusWorldLoc, void* InterpSpeedRange, void* InFocusFOV, float CameraFOV, bool bAlwaysFocus, bool bAdjustCamera, bool bIgnoreTrace, float FocusPitchOffsetDeg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.SetFocusOnLoc" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( Vector* )( params + 0 ) = FocusWorldLoc;
				*( void** )( params + 12 ) = InterpSpeedRange;
				*( void** )( params + 20 ) = InFocusFOV;
				*( float* )( params + 28 ) = CameraFOV;
				*( bool* )( params + 32 ) = bAlwaysFocus;
				*( bool* )( params + 36 ) = bAdjustCamera;
				*( bool* )( params + 40 ) = bIgnoreTrace;
				*( float* )( params + 44 ) = FocusPitchOffsetDeg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFocusOnActor( class Actor* FocusActor, ScriptName FocusBoneName, void* InterpSpeedRange, void* InFocusFOV, float CameraFOV, bool bAlwaysFocus, bool bAdjustCamera, bool bIgnoreTrace, float FocusPitchOffsetDeg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.SetFocusOnActor" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( class Actor** )( params + 0 ) = FocusActor;
				*( ScriptName* )( params + 4 ) = FocusBoneName;
				*( void** )( params + 12 ) = InterpSpeedRange;
				*( void** )( params + 20 ) = InFocusFOV;
				*( float* )( params + 28 ) = CameraFOV;
				*( bool* )( params + 32 ) = bAlwaysFocus;
				*( bool* )( params + 36 ) = bAdjustCamera;
				*( bool* )( params + 40 ) = bIgnoreTrace;
				*( float* )( params + 44 ) = FocusPitchOffsetDeg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Actor* GetFocusActor(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.GetFocusActor" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			void ClearFocusPoint( bool bLeaveCameraRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.ClearFocusPoint" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bLeaveCameraRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateFocusPoint( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.UpdateFocusPoint" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetActualFocusLocation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.GetActualFocusLocation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void AdjustFocusPointInterpolation( Rotator Delta )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.AdjustFocusPointInterpolation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )( params + 0 ) = Delta;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GameThirdPersonCameraMode* FindBestCameraMode( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.FindBestCameraMode" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GameThirdPersonCameraMode** )( params + function->return_val_offset() );
			}

			void ProcessViewRotation( float DeltaTime, class Actor* ViewTarget, Rotator &out_ViewRotation, Rotator &out_DeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.ProcessViewRotation" );
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

			void OnBecomeActive( class GameCameraBase* OldCamera )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.OnBecomeActive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCameraBase** )( params + 0 ) = OldCamera;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ModifyPostProcessSettings( void* &PP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.ModifyPostProcessSettings" );
				byte *params = ( byte* )( malloc( 220 ) );
				*( void** )( params + 0 ) = PP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PP = *( void** )( params + 0 );
			}

			void ResetInterpolation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameThirdPersonCamera.ResetInterpolation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
