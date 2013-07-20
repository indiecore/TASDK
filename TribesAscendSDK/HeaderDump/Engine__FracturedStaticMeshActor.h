#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.FracturedStaticMeshActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.FracturedStaticMeshActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.FracturedStaticMeshActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FracturedStaticMeshActor : public Actor
	{
	public:
			bool IsFracturedByDamageType( ScriptClass* dmgType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.IsFracturedByDamageType" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = dmgType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FractureEffectIsRelevant( bool bForceDedicated, class Pawn* EffectInstigator, byte &bWantPhysChunksAndParticles )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.FractureEffectIsRelevant" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( bool* )params = bForceDedicated;
				*( class Pawn** )( params + 4 ) = EffectInstigator;
				*( byte* )( params + 8 ) = bWantPhysChunksAndParticles;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				bWantPhysChunksAndParticles = *( byte* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( MaterialInterface, MI_LoseChunkPreviousMaterial )
			ADD_OBJECT( SoundCue, SingleChunkFractureSound )
			ADD_OBJECT( SoundCue, ExplosionFractureSound )
			ADD_VAR( ::FloatProperty, FractureCullMaxDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FractureCullMinDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ChunkHealthScale, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bBreakChunksOnActorTouch, 0x2 )
			ADD_VAR( ::BoolProperty, bHasShownMissingSoundWarning, 0x1 )
			ADD_VAR( ::IntProperty, MaxPartsToSpawnAtOnce, 0xFFFFFFFF )
			class FracturedStaticMeshPart* SpawnPart( int ChunkIndex, Vector InitialVel, Vector InitialAngVel, float RelativeScale, bool bExplosion )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.SpawnPart" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( int* )params = ChunkIndex;
				*( Vector* )( params + 4 ) = InitialVel;
				*( Vector* )( params + 16 ) = InitialAngVel;
				*( float* )( params + 28 ) = RelativeScale;
				*( bool* )( params + 32 ) = bExplosion;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class FracturedStaticMeshPart** )( params + function->return_val_offset() );
			}

			class FracturedStaticMeshPart* SpawnPartMulti( Vector InitialVel, Vector InitialAngVel, float RelativeScale, bool bExplosion )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.SpawnPartMulti" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( Vector* )( params + 12 ) = InitialVel;
				*( Vector* )( params + 24 ) = InitialAngVel;
				*( float* )( params + 36 ) = RelativeScale;
				*( bool* )( params + 40 ) = bExplosion;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class FracturedStaticMeshPart** )( params + function->return_val_offset() );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetHealth(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.ResetHealth" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BreakOffIsolatedIslands( Vector ChunkDir, bool bWantPhysChunks )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.BreakOffIsolatedIslands" );
				byte *params = ( byte* )( malloc( 52 ) );
				*( Vector* )( params + 24 ) = ChunkDir;
				*( bool* )( params + 48 ) = bWantPhysChunks;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SpawnDeferredParts(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.SpawnDeferredParts" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RemoveDecals( int IndexToRemoveDecalsFrom )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.RemoveDecals" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = IndexToRemoveDecalsFrom;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeDamage( int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.TakeDamage" );
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

			void Explode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.Explode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BreakOffPartsInRadius( Vector Origin, float Radius, float RBStrength, bool bWantPhysChunksAndParticles )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.BreakOffPartsInRadius" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = Origin;
				*( float* )( params + 12 ) = Radius;
				*( float* )( params + 16 ) = RBStrength;
				*( bool* )( params + 20 ) = bWantPhysChunksAndParticles;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetVisibility(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.ResetVisibility" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HideOneFragment(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.HideOneFragment" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HideFragmentsToMaximizeMemoryUsage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.HideFragmentsToMaximizeMemoryUsage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLoseChunkReplacementMaterial(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.SetLoseChunkReplacementMaterial" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyHitByExplosion( class Controller* InstigatorController, float DamageAmount, ScriptClass* dmgType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshActor.NotifyHitByExplosion" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Controller** )params = InstigatorController;
				*( float* )( params + 4 ) = DamageAmount;
				*( ScriptClass** )( params + 8 ) = dmgType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
