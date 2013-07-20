#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.KActorFromStatic." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.KActorFromStatic." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.KActorFromStatic." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class KActorFromStatic : public KActor
	{
	public:
			class KActorFromStatic* MakeDynamic(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.KActorFromStatic.MakeDynamic" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class KActorFromStatic** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, MaxImpulseSpeed, 0xFFFFFFFF )
			ADD_OBJECT( Actor, MyStaticMeshActor )
			void DisablePrecomputedLighting(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.KActorFromStatic.DisablePrecomputedLighting" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSleepRBPhysics(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.KActorFromStatic.OnSleepRBPhysics" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnWakeRBPhysics(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.KActorFromStatic.OnWakeRBPhysics" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BecomeStatic(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.KActorFromStatic.BecomeStatic" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MakeStatic(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.KActorFromStatic.MakeStatic" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyImpulse( Vector ImpulseDir, float ImpulseMag, Vector HitLocation, void* HitInfo, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.KActorFromStatic.ApplyImpulse" );
				byte *params = ( byte* )( malloc( 60 ) );
				*( Vector* )params = ImpulseDir;
				*( float* )( params + 12 ) = ImpulseMag;
				*( Vector* )( params + 16 ) = HitLocation;
				*( void** )( params + 28 ) = HitInfo;
				*( ScriptClass** )( params + 56 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceiveImpulse( class Pawn* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.KActorFromStatic.ReceiveImpulse" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Pawn** )params = Other;
				*( Vector* )( params + 4 ) = HitLocation;
				*( Vector* )( params + 16 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Bump( class Actor* Other, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.KActorFromStatic.Bump" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 8 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Touch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.KActorFromStatic.Touch" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeRadiusDamage( class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.KActorFromStatic.TakeRadiusDamage" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( class Controller** )params = InstigatedBy;
				*( float* )( params + 4 ) = BaseDamage;
				*( float* )( params + 8 ) = DamageRadius;
				*( ScriptClass** )( params + 12 ) = DamageType;
				*( float* )( params + 16 ) = Momentum;
				*( Vector* )( params + 20 ) = HurtOrigin;
				*( bool* )( params + 32 ) = bFullDamage;
				*( class Actor** )( params + 36 ) = DamageCauser;
				*( float* )( params + 40 ) = DamageFalloffExponent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
