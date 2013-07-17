#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameExplosionActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameExplosionActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameExplosionActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameExplosionActor : public Actor
	{
	public:
			ADD_STRUCT( ::VectorProperty, ExplosionDirection, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DirectionalExplosionMinDot, 0xFFFFFFFF )
			ADD_OBJECT( Controller, AttacheeController )
			ADD_OBJECT( Actor, Attachee )
			ADD_STRUCT( ::VectorProperty, HitLocationFromPhysMaterialTrace, 0xFFFFFFFF )
			ADD_OBJECT( Actor, HitActorFromPhysMaterialTrace )
			ADD_OBJECT( Controller, InstigatorController )
			ADD_OBJECT( GameExplosion, ExplosionTemplate )
			ADD_VAR( ::FloatProperty, RadialBlurMaxBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RadialBlurFadeTimeRemaining, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RadialBlurFadeTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LightInitialBrightness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LightFadeTimeRemaining, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LightFadeTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDrawDebug, 0x4 )
			ADD_VAR( ::BoolProperty, bExplodeMoreThanOnce, 0x2 )
			ADD_VAR( ::BoolProperty, bHasExploded, 0x1 )
			void PreBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.PreBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class PhysicalMaterial* GetPhysicalMaterial(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.GetPhysicalMaterial" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PhysicalMaterial** )( params + function->return_val_offset() );
			}

			bool DoFullDamageToActor( class Actor* Victim )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.DoFullDamageToActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Victim;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsBehindExplosion( class Actor* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.IsBehindExplosion" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float BoxDistanceToPoint( Vector Start, void* BBox )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.BoxDistanceToPoint" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( Vector* )( params + 0 ) = Start;
				*( void** )( params + 12 ) = BBox;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void DoExplosionDamage( bool bCauseDamage, bool bCauseEffects )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.DoExplosionDamage" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bCauseDamage;
				*( bool* )( params + 4 ) = bCauseEffects;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetEffectCheckRadius(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.GetEffectCheckRadius" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void SpecialPawnEffectsFor( class GamePawn* VictimPawn, float VictimDist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.SpecialPawnEffectsFor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class GamePawn** )( params + 0 ) = VictimPawn;
				*( float* )( params + 4 ) = VictimDist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateExplosionTemplateWithPerMaterialFX( class PhysicalMaterial* PhysMaterial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.UpdateExplosionTemplateWithPerMaterialFX" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PhysicalMaterial** )( params + 0 ) = PhysMaterial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnExplosionParticleSystem( class ParticleSystem* Template )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.SpawnExplosionParticleSystem" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class ParticleSystem** )( params + 0 ) = Template;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnExplosionDecal(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.SpawnExplosionDecal" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnExplosionFogVolume(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.SpawnExplosionFogVolume" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Explode( class GameExplosion* NewExplosionTemplate, Vector Direction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.Explode" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class GameExplosion** )( params + 0 ) = NewExplosionTemplate;
				*( Vector* )( params + 4 ) = Direction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DelayedExplosionDamage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.DelayedExplosionDamage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawDebug(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.DrawDebug" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoExplosionCameraEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.DoExplosionCameraEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnCameraLensEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.SpawnCameraLensEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class CameraShake* ChooseCameraShake( Vector Epicenter, class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameExplosionActor.ChooseCameraShake" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = Epicenter;
				*( class PlayerController** )( params + 12 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class CameraShake** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
