#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.FracturedStaticMeshPart." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.FracturedStaticMeshPart." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.FracturedStaticMeshPart." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FracturedStaticMeshPart : public FracturedStaticMeshActor
	{
	public:
			ADD_VAR( ::FloatProperty, LastImpactSoundTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentVibrationLevel, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, OldVelocity, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, AsleepRBChannel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FracPartGravScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PartPoolIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastSpawnTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCompositeThatExplodesOnImpact, 0x4 )
			ADD_VAR( ::BoolProperty, bChangeRBChannelWhenAsleep, 0x2 )
			ADD_VAR( ::BoolProperty, bHasBeenRecycled, 0x1 )
			ADD_OBJECT( FracturedStaticMeshActor, BaseFracturedMeshActor )
			ADD_VAR( ::FloatProperty, DestroyPartRadiusFactor, 0xFFFFFFFF )
			void Initialize(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshPart.Initialize" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RecyclePart( bool bAddToFreePool )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshPart.RecyclePart" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bAddToFreePool;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeDamage( int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshPart.TakeDamage" );
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

			void TryToCleanUp(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshPart.TryToCleanUp" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FellOutOfWorld( ScriptClass* dmgType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshPart.FellOutOfWorld" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = dmgType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Explode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshPart.Explode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BreakOffPartsInRadius( Vector Origin, float Radius, float RBStrength, bool bWantPhysChunksAndParticles )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshPart.BreakOffPartsInRadius" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = Origin;
				*( float* )( params + 12 ) = Radius;
				*( float* )( params + 16 ) = RBStrength;
				*( bool* )( params + 20 ) = bWantPhysChunksAndParticles;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
