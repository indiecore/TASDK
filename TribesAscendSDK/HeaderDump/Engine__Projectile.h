#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Projectile." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Projectile." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Projectile." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Projectile : public Actor
	{
	public:
			ADD_VAR( ::FloatProperty, NetCullDistanceSquared, 0xFFFFFFFF )
			ADD_OBJECT( Actor, ImpactedActor )
			ADD_OBJECT( Controller, InstigatorController )
			ADD_OBJECT( SoundCue, ImpactSound )
			ADD_OBJECT( SoundCue, SpawnSound )
			ADD_OBJECT( ScriptClass, MyDamageType )
			ADD_VAR( ::FloatProperty, MomentumTransfer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DamageRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Damage, 0xFFFFFFFF )
			ADD_OBJECT( Actor, ZeroCollider )
			ADD_VAR( ::BoolProperty, bRotationFollowsVelocity, 0x8 )
			ADD_VAR( ::BoolProperty, bBegunPlay, 0x4 )
			ADD_VAR( ::BoolProperty, bBlockedByInstigator, 0x2 )
			ADD_VAR( ::BoolProperty, bSwitchToZeroCollision, 0x1 )
			ADD_VAR( ::FloatProperty, MaxSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Speed, 0xFFFFFFFF )
			bool EncroachingOn( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.EncroachingOn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PreBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.PreBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Init( Vector Direction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.Init" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = Direction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetTeamNum(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.GetTeamNum" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool CanSplash(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.CanSplash" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ProjectileHurtRadius( Vector HurtOrigin, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.ProjectileHurtRadius" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = HurtOrigin;
				*( Vector* )( params + 12 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HurtRadius( float DamageAmount, float InDamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, class Actor* IgnoredActor, class Controller* InstigatedByController, bool bDoFullDamage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.HurtRadius" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( float* )params = DamageAmount;
				*( float* )( params + 4 ) = InDamageRadius;
				*( ScriptClass** )( params + 8 ) = DamageType;
				*( float* )( params + 12 ) = Momentum;
				*( Vector* )( params + 16 ) = HurtOrigin;
				*( class Actor** )( params + 28 ) = IgnoredActor;
				*( class Controller** )( params + 32 ) = InstigatedByController;
				*( bool* )( params + 36 ) = bDoFullDamage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Touch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.Touch" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessTouch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.ProcessTouch" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 4 ) = HitLocation;
				*( Vector* )( params + 16 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HitWall( Vector HitNormal, class Actor* Wall )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.HitWall" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = Wall;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EncroachedBy( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.EncroachedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Explode( Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.Explode" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = HitLocation;
				*( Vector* )( params + 12 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RandSpin( float spinRate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.RandSpin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = spinRate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsStationary(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.IsStationary" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void FellOutOfWorld( ScriptClass* dmgType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.FellOutOfWorld" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = dmgType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetTimeToLocation( Vector TargetLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.GetTimeToLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = TargetLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float StaticGetTimeToLocation( Vector TargetLoc, Vector StartLoc, class Controller* RequestedBy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.StaticGetTimeToLocation" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )params = TargetLoc;
				*( Vector* )( params + 12 ) = StartLoc;
				*( class Controller** )( params + 24 ) = RequestedBy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetRange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.GetRange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void ApplyFluidSurfaceImpact( class FluidSurfaceActor* Fluid, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Projectile.ApplyFluidSurfaceImpact" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class FluidSurfaceActor** )params = Fluid;
				*( Vector* )( params + 4 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
