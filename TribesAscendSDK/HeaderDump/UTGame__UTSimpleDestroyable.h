#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTSimpleDestroyable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTSimpleDestroyable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTSimpleDestroyable." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTSimpleDestroyable : public DynamicSMActor
	{
	public:
			ADD_VAR( ::FloatProperty, TimeToRespawn, 0xFFFFFFFF )
			ADD_OBJECT( StaticMesh, RespawnStaticMesh )
			ADD_VAR( ::FloatProperty, RespawnTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, SpawnPhysMeshAngularVel, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, SpawnPhysMeshLinearVel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpawnPhysMeshLifeSpan, 0xFFFFFFFF )
			ADD_OBJECT( StaticMesh, SpawnPhysMesh )
			ADD_OBJECT( ParticleSystem, ParticlesOnDestroy )
			ADD_OBJECT( SoundCue, SoundOnDestroy )
			ADD_OBJECT( StaticMesh, MeshOnDestroy )
			ADD_VAR( ::BoolProperty, bDestroyed, 0x8 )
			ADD_VAR( ::BoolProperty, bDestroyOnVehicleTouch, 0x4 )
			ADD_VAR( ::BoolProperty, bDestroyOnPlayerTouch, 0x2 )
			ADD_VAR( ::BoolProperty, bDestroyOnDamage, 0x1 )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSimpleDestroyable.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GoBoom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSimpleDestroyable.GoBoom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RespawnDestructible(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSimpleDestroyable.RespawnDestructible" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeDamage( int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSimpleDestroyable.TakeDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )( params + 0 ) = DamageAmount;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Touch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSimpleDestroyable.Touch" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )( params + 0 ) = Other;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckRespawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSimpleDestroyable.CheckRespawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
