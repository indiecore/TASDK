#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTWeaponAttachment." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTWeaponAttachment." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTWeaponAttachment." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTWeaponAttachment : public Actor
	{
	public:
			ADD_VAR( ::FloatProperty, MaxFireEffectDistance, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, WeapAnimType, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, AltFireAnim, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, FireAnim, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DistFactorForRefPose, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxDecalRangeSq, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, WeaponClass )
			ADD_VAR( ::FloatProperty, MaxImpactEffectDistance, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, BulletWhip )
			ADD_VAR( ::NameProperty, AttachmentSocket, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MuzzleFlashDuration, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, MuzzleFlashLightClass )
			ADD_VAR( ::BoolProperty, bMakeSplash, 0x8 )
			ADD_VAR( ::BoolProperty, bSuppressSounds, 0x4 )
			ADD_VAR( ::BoolProperty, bAlignToSurfaceNormal, 0x2 )
			ADD_VAR( ::BoolProperty, bMuzzleFlashPSCLoops, 0x1 )
			ADD_OBJECT( ParticleSystem, MuzzleFlashAltPSCTemplate )
			ADD_OBJECT( ParticleSystem, MuzzleFlashPSCTemplate )
			ADD_VAR( ::NameProperty, MuzzleFlashSocket, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, SplashEffect )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckToForceRefPose(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.CheckToForceRefPose" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateOverlayMesh(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.CreateOverlayMesh" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSkin( class Material* NewMaterial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.SetSkin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Material** )( params + 0 ) = NewMaterial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMuzzleFlashParams(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.SetMuzzleFlashParams" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AttachTo( class UTPawn* OwnerPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.AttachTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPawn** )( params + 0 ) = OwnerPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPuttingDownWeapon( bool bNowPuttingDown )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.SetPuttingDownWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNowPuttingDown;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetachFrom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.DetachFrom" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MuzzleFlashTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.MuzzleFlashTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CauseMuzzleFlash(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.CauseMuzzleFlash" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopMuzzleFlash(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.StopMuzzleFlash" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FirstPersonFireEffects( class Weapon* PawnWeapon, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.FirstPersonFireEffects" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Weapon** )( params + 0 ) = PawnWeapon;
				*( Vector* )( params + 4 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopFirstPersonFireEffects( class Weapon* PawnWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.StopFirstPersonFireEffects" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = PawnWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ThirdPersonFireEffects( Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.ThirdPersonFireEffects" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopThirdPersonFireEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.StopThirdPersonFireEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetImpactEffect( class PhysicalMaterial* HitMaterial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.GetImpactEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PhysicalMaterial** )( params + 0 ) = HitMaterial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			bool AllowImpactEffects( class Actor* HitActor, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.AllowImpactEffects" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Actor** )( params + 0 ) = HitActor;
				*( Vector* )( params + 4 ) = HitLocation;
				*( Vector* )( params + 16 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetImpactedActor( class Actor* HitActor, Vector HitLocation, Vector HitNormal, void* HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.SetImpactedActor" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( class Actor** )( params + 0 ) = HitActor;
				*( Vector* )( params + 4 ) = HitLocation;
				*( Vector* )( params + 16 ) = HitNormal;
				*( void** )( params + 28 ) = HitInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayImpactEffects( Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.PlayImpactEffects" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckBulletWhip( Vector FireDir, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.CheckBulletWhip" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = FireDir;
				*( Vector* )( params + 12 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetWeaponOverlayFlags( class UTPawn* OwnerPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.SetWeaponOverlayFlags" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPawn** )( params + 0 ) = OwnerPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangeVisibility( bool bIsVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.ChangeVisibility" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bIsVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FireModeUpdated( byte FiringMode, bool bViaReplication )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.FireModeUpdated" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = FiringMode;
				*( bool* )( params + 4 ) = bViaReplication;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetEffectLocation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponAttachment.GetEffectLocation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
