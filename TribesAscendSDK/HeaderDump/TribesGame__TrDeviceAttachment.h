#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDeviceAttachment." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDeviceAttachment." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDeviceAttachment." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDeviceAttachment : public UTWeaponAttachment
	{
	public:
			ADD_VAR( ::NameProperty, m_nmRidingAsPassengerFireAnimName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fShowTracerDistance, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_TracerType, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, m_TracerBeamTemplate )
			ADD_VAR( ::BoolProperty, m_bScaleFireAnimRate, 0x4 )
			ADD_VAR( ::BoolProperty, m_bSpawnTracerBeams, 0x2 )
			ADD_VAR( ::BoolProperty, m_bSpawnTracers, 0x1 )
			ADD_VAR( ::NameProperty, m_nmHeavyAimProfileName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_nmLightMedAimProfileName, 0xFFFFFFFF )
			void AttachTo( class UTPawn* OwnerPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.AttachTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPawn** )params = OwnerPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitAnims( class TrPawn* TRP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.InitAnims" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPawn** )params = TRP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetachFrom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.DetachFrom" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPuttingDownWeapon( bool bNowPuttingDown )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.SetPuttingDownWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNowPuttingDown;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldFireTracer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.ShouldFireTracer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShouldFireTracerBeam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.ShouldFireTracerBeam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ThirdPersonFireEffects( Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.ThirdPersonFireEffects" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopThirdPersonFireEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.StopThirdPersonFireEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FirstPersonFireEffects( class Weapon* PawnWeapon, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.FirstPersonFireEffects" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Weapon** )params = PawnWeapon;
				*( Vector* )( params + 4 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnTracerBeam( Vector Start, Vector End )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.SpawnTracerBeam" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = Start;
				*( Vector* )( params + 12 ) = End;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class TrProj_Tracer* SpawnTracerEffect( Vector HitLocation, float HitDistance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.SpawnTracerEffect" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitLocation;
				*( float* )( params + 12 ) = HitDistance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrProj_Tracer** )( params + function->return_val_offset() );
			}

			class TrProj_Tracer* GetTracer( Vector SpawnLocation, Rotator SpawnRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.GetTracer" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = SpawnLocation;
				*( Rotator* )( params + 12 ) = SpawnRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrProj_Tracer** )( params + function->return_val_offset() );
			}

			void PlayReload(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.PlayReload" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayImpactEffects( Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.PlayImpactEffects" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayImpactSound( class Actor* HitActor, class SoundCue* SoundToPlay, Vector FireDir, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.PlayImpactSound" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )params = HitActor;
				*( class SoundCue** )( params + 4 ) = SoundToPlay;
				*( Vector* )( params + 8 ) = FireDir;
				*( Vector* )( params + 20 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetImpactEffect( class PhysicalMaterial* HitMaterial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeviceAttachment.GetImpactEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PhysicalMaterial** )params = HitMaterial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
