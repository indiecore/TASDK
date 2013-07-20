#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ApexDestructibleActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ApexDestructibleActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ApexDestructibleActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ApexDestructibleActor : public Actor
	{
	public:
			ADD_VAR( ::BoolProperty, bFractureMaterialOverride, 0x1 )
			void SpawnFractureEmitter( class ParticleSystem* EmitterTemplate, Vector SpawnLocation, Vector SpawnDirection )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ApexDestructibleActor.SpawnFractureEmitter" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class ParticleSystem** )params = EmitterTemplate;
				*( Vector* )( params + 4 ) = SpawnLocation;
				*( Vector* )( params + 16 ) = SpawnDirection;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CacheFractureEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ApexDestructibleActor.CacheFractureEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ApexDestructibleActor.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeDamage( int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ApexDestructibleActor.TakeDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )params = Damage;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeRadiusDamage( class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ApexDestructibleActor.TakeRadiusDamage" );
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
