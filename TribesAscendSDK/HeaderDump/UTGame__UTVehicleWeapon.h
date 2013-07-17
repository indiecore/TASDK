#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTVehicleWeapon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTVehicleWeapon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTVehicleWeapon." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTVehicleWeapon : public UTWeapon
	{
	public:
			float GetMaxFinalAimAdjustment(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.GetMaxFinalAimAdjustment" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, SeatIndex, 0xFFFFFFFF )
			ADD_OBJECT( UTVehicle, MyVehicle )
			ADD_VAR( ::BoolProperty, bIgnoreSocketPitchRotation, 0x4 )
			ADD_VAR( ::BoolProperty, bIgnoreDownwardPitch, 0x8 )
			Rotator GetAdjustedAim( Vector StartFireLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.GetAdjustedAim" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = StartFireLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			ScriptName GetFireTriggerTag( int BarrelIndex, int FireMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.GetFireTriggerTag" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = BarrelIndex;
				*( int* )( params + 4 ) = FireMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void* GetImpactEffect( class Actor* HitActor, class PhysicalMaterial* HitMaterial, byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.GetImpactEffect" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( class Actor** )( params + 0 ) = HitActor;
				*( class PhysicalMaterial** )( params + 4 ) = HitMaterial;
				*( byte* )( params + 8 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( SoundCue, BulletWhip )
			ADD_OBJECT( ScriptClass, VehicleClass )
			ADD_VAR( ::BoolProperty, bDebugTurret, 0x10 )
			ADD_VAR( ::BoolProperty, bCurrentlyZoomed, 0x2 )
			ADD_VAR( ::BoolProperty, bPlaySoundFromSocket, 0x1 )
			ADD_VAR( ::FloatProperty, MaxFinalAimAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentCrosshairScaling, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastInCorrectAimTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastCorrectAimTime, 0xFFFFFFFF )
			bool CanHitDesiredTarget( Vector SocketLocation, Rotator SocketRotation, Vector DesiredAimPoint, class Actor* TargetActor, Vector &RealAimPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.CanHitDesiredTarget" );
				byte *params = ( byte* )( malloc( 52 ) );
				*( Vector* )( params + 0 ) = SocketLocation;
				*( Rotator* )( params + 12 ) = SocketRotation;
				*( Vector* )( params + 24 ) = DesiredAimPoint;
				*( class Actor** )( params + 36 ) = TargetActor;
				*( Vector* )( params + 40 ) = RealAimPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				RealAimPoint = *( Vector* )( params + 40 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DrawKillIcon( class Canvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.DrawKillIcon" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				*( float* )( params + 4 ) = ScreenX;
				*( float* )( params + 8 ) = ScreenY;
				*( float* )( params + 12 ) = HUDScaleX;
				*( float* )( params + 16 ) = HUDScaleY;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetCrosshairScaling( class HUD* HUD )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.GetCrosshairScaling" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class HUD** )( params + 0 ) = HUD;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawWeaponCrosshair( class HUD* HUD )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.DrawWeaponCrosshair" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class HUD** )( params + 0 ) = HUD;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetDesiredAimPoint( class Actor* &TargetActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.GetDesiredAimPoint" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = TargetActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				TargetActor = *( class Actor** )( params + 0 );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void GetFireStartLocationAndRotation( Vector &StartLocation, Rotator &StartRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.GetFireStartLocationAndRotation" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = StartLocation;
				*( Rotator* )( params + 12 ) = StartRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				StartLocation = *( Vector* )( params + 0 );
				StartRotation = *( Rotator* )( params + 12 );
			}

			bool IsAimCorrect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.IsAimCorrect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float GetFireInterval( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.GetFireInterval" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void AttachWeaponTo( ScriptName SocketName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.AttachWeaponTo" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 4 ) = SocketName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetachWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.DetachWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Activate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.Activate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PutDownWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.PutDownWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetPhysicalFireStartLoc( Vector AimDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.GetPhysicalFireStartLoc" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = AimDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void BeginFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.BeginFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.EndFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Projectile* ProjectileFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.ProjectileFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Projectile** )( params + function->return_val_offset() );
			}

			Vector InstantFireStartTrace(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.InstantFireStartTrace" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector InstantFireEndTrace( Vector StartTrace )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.InstantFireEndTrace" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = StartTrace;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			class Actor* GetTraceOwner(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.GetTraceOwner" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			void NotifyVehicleDeployed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.NotifyVehicleDeployed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyVehicleUndeployed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.NotifyVehicleUndeployed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WeaponPlaySound( class SoundCue* Sound, float NoiseLoudness, bool bStopWhenOwnerDestroyed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.WeaponPlaySound" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class SoundCue** )( params + 0 ) = Sound;
				*( float* )( params + 4 ) = NoiseLoudness;
				*( bool* )( params + 8 ) = bStopWhenOwnerDestroyed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetZoomedState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.GetZoomedState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void ServerSetZoom( bool bNowZoomed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.ServerSetZoom" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNowZoomed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartZoom( class UTPlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.StartZoom" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndZoom( class UTPlayerController* PC, bool bReturningTo3P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicleWeapon.EndZoom" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerController** )( params + 0 ) = PC;
				*( bool* )( params + 4 ) = bReturningTo3P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
