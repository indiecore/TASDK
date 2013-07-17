#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Camera." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Camera." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Camera." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Camera : public Actor
	{
	public:
			class CameraModifier* CreateCameraModifier( ScriptClass* ModifierClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.CreateCameraModifier" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = ModifierClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class CameraModifier** )( params + function->return_val_offset() );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( CameraModifier_CameraShake, CameraShakeCamMod )
			ADD_OBJECT( ScriptClass, CameraShakeCamModClass )
			ADD_OBJECT( CameraAnimInst, AnimInstPool )
			ADD_OBJECT( DynamicCameraActor, AnimCameraActor )
			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyCameraModifiers( float DeltaTime, void* &OutPOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.ApplyCameraModifiers" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( float* )( params + 0 ) = DeltaTime;
				*( void** )( params + 4 ) = OutPOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutPOV = *( void** )( params + 4 );
			}

			void InitializeFor( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.InitializeFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, DefaultFOV, 0xFFFFFFFF )
			ADD_OBJECT( PlayerController, PCOwner )
			void SetViewTarget( class Actor* NewViewTarget, void* TransitionParams )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.SetViewTarget" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Actor** )( params + 0 ) = NewViewTarget;
				*( void** )( params + 4 ) = TransitionParams;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetFOVAngle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.GetFOVAngle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bLockedFOV, 0x1 )
			ADD_VAR( ::FloatProperty, LockedFOV, 0xFFFFFFFF )
			void SetFOV( float NewFOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.SetFOV" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = NewFOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetCameraViewPoint( Vector &OutCamLoc, Rotator &OutCamRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.GetCameraViewPoint" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = OutCamLoc;
				*( Rotator* )( params + 12 ) = OutCamRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutCamLoc = *( Vector* )( params + 0 );
				OutCamRot = *( Rotator* )( params + 12 );
			}

			Rotator GetCameraRotation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.GetCameraRotation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void SetDesiredColorScale( Vector NewColorScale, float InterpTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.SetDesiredColorScale" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = NewColorScale;
				*( float* )( params + 12 ) = InterpTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bEnableColorScaling, 0x8 )
			ADD_STRUCT( ::VectorProperty, ColorScale, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, OriginalColorScale, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, DesiredColorScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ColorScaleInterpStartTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ColorScaleInterpDuration, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnableColorScaleInterp, 0x10 )
			void UpdateCamera( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.UpdateCamera" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bConstrainAspectRatio, 0x2 )
			ADD_VAR( ::FloatProperty, CamOverridePostProcessAlpha, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConstrainedAspectRatio, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendTimeToGo, 0xFFFFFFFF )
			void* BlendViewTargets( void* &A, void* &B, float Alpha )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.BlendViewTargets" );
				byte *params = ( byte* )( malloc( 92 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 44 ) = B;
				*( float* )( params + 88 ) = Alpha;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( void** )( params + 0 );
				B = *( void** )( params + 44 );
				return *( void** )( params + function->return_val_offset() );
			}

			void FillCameraCache( void* &NewPOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.FillCameraCache" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( void** )( params + 0 ) = NewPOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				NewPOV = *( void** )( params + 0 );
			}

			ADD_VAR( ::BoolProperty, bEnableFading, 0x4 )
			ADD_VAR( ::FloatProperty, FadeTimeRemaining, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeAmount, 0xFFFFFFFF )
			void CheckViewTarget( void* &VT )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.CheckViewTarget" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( void** )( params + 0 ) = VT;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				VT = *( void** )( params + 0 );
			}

			ADD_STRUCT( ::VectorProperty, FreeCamOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FreeCamDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OffAxisPitchAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OffAxisYawAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DefaultAspectRatio, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, CameraStyle, 0xFFFFFFFF )
			void UpdateViewTarget( void* &OutVT, float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.UpdateViewTarget" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( void** )( params + 0 ) = OutVT;
				*( float* )( params + 44 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutVT = *( void** )( params + 0 );
			}

			void ProcessViewRotation( float DeltaTime, Rotator &OutViewRotation, Rotator &OutDeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.ProcessViewRotation" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( float* )( params + 0 ) = DeltaTime;
				*( Rotator* )( params + 4 ) = OutViewRotation;
				*( Rotator* )( params + 16 ) = OutDeltaRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutViewRotation = *( Rotator* )( params + 4 );
				OutDeltaRot = *( Rotator* )( params + 16 );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )( params + 0 ) = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			class EmitterCameraLensEffectBase* FindCameraLensEffect( ScriptClass* LensEffectEmitterClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.FindCameraLensEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = LensEffectEmitterClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class EmitterCameraLensEffectBase** )( params + function->return_val_offset() );
			}

			void AddCameraLensEffect( ScriptClass* LensEffectEmitterClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.AddCameraLensEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = LensEffectEmitterClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveCameraLensEffect( class EmitterCameraLensEffectBase* Emitter )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.RemoveCameraLensEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class EmitterCameraLensEffectBase** )( params + 0 ) = Emitter;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearCameraLensEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.ClearCameraLensEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayCameraShake( class CameraShake* Shake, float Scale, byte PlaySpace, Rotator UserPlaySpaceRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.PlayCameraShake" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( class CameraShake** )( params + 0 ) = Shake;
				*( float* )( params + 4 ) = Scale;
				*( byte* )( params + 8 ) = PlaySpace;
				*( Rotator* )( params + 12 ) = UserPlaySpaceRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopCameraShake( class CameraShake* Shake )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.StopCameraShake" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class CameraShake** )( params + 0 ) = Shake;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float CalcRadialShakeScale( class Camera* Cam, Vector Epicenter, float InnerRadius, float OuterRadius, float Falloff )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.CalcRadialShakeScale" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Camera** )( params + 0 ) = Cam;
				*( Vector* )( params + 4 ) = Epicenter;
				*( float* )( params + 16 ) = InnerRadius;
				*( float* )( params + 20 ) = OuterRadius;
				*( float* )( params + 24 ) = Falloff;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void PlayWorldCameraShake( class CameraShake* Shake, class Actor* ShakeInstigator, Vector Epicenter, float InnerRadius, float OuterRadius, float Falloff, bool bTryForceFeedback, bool bOrientShakeTowardsEpicenter )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.PlayWorldCameraShake" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( class CameraShake** )( params + 0 ) = Shake;
				*( class Actor** )( params + 4 ) = ShakeInstigator;
				*( Vector* )( params + 8 ) = Epicenter;
				*( float* )( params + 20 ) = InnerRadius;
				*( float* )( params + 24 ) = OuterRadius;
				*( float* )( params + 28 ) = Falloff;
				*( bool* )( params + 32 ) = bTryForceFeedback;
				*( bool* )( params + 36 ) = bOrientShakeTowardsEpicenter;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearAllCameraShakes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.ClearAllCameraShakes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class CameraAnimInst* PlayCameraAnim( class CameraAnim* Anim, float Rate, float Scale, float BlendInTime, float BlendOutTime, bool bLoop, bool bRandomStartTime, float Duration, bool bSingleInstance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.PlayCameraAnim" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class CameraAnim** )( params + 0 ) = Anim;
				*( float* )( params + 4 ) = Rate;
				*( float* )( params + 8 ) = Scale;
				*( float* )( params + 12 ) = BlendInTime;
				*( float* )( params + 16 ) = BlendOutTime;
				*( bool* )( params + 20 ) = bLoop;
				*( bool* )( params + 24 ) = bRandomStartTime;
				*( float* )( params + 28 ) = Duration;
				*( bool* )( params + 32 ) = bSingleInstance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class CameraAnimInst** )( params + function->return_val_offset() );
			}

			void StopAllCameraAnims( bool bImmediate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.StopAllCameraAnims" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bImmediate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopAllCameraAnimsByType( class CameraAnim* Anim, bool bImmediate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.StopAllCameraAnimsByType" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class CameraAnim** )( params + 0 ) = Anim;
				*( bool* )( params + 4 ) = bImmediate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopCameraAnim( class CameraAnimInst* AnimInst, bool bImmediate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Camera.StopCameraAnim" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class CameraAnimInst** )( params + 0 ) = AnimInst;
				*( bool* )( params + 4 ) = bImmediate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
