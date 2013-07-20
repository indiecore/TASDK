#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrProj_SpikeGrenade." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrProj_SpikeGrenade." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrProj_SpikeGrenade." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProj_SpikeGrenade : public TrProj_Grenade
	{
	public:
			ADD_OBJECT( SoundCue, m_FractalExplosionSound )
			ADD_OBJECT( ParticleSystem, m_FractalBeamTemplate )
			ADD_OBJECT( ParticleSystem, m_FractalExplosionTemplate )
			ADD_VAR( ::FloatProperty, m_fFractalDamageRadius, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nFractalDamage, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, r_vFlashExplosionLocation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vAscentLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fZFractalShotDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFractalShotDistance, 0xFFFFFFFF )
			ADD_OBJECT( SkelControlSingleBone, m_AscendControl )
			ADD_STRUCT( ::VectorProperty, m_CachedHitNormal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAscentHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAscentTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFractalInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFractalTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingFractalTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bStartedFractal, 0x1 )
			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_SpikeGrenade.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_SpikeGrenade.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitProjectile( Vector Direction, ScriptClass* ClassToInherit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_SpikeGrenade.InitProjectile" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = Direction;
				*( ScriptClass** )( params + 12 ) = ClassToInherit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Explode( Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_SpikeGrenade.Explode" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = HitLocation;
				*( Vector* )( params + 12 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientReceivedExplosionLocation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_SpikeGrenade.ClientReceivedExplosionLocation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsFractalActive(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_SpikeGrenade.IsFractalActive" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void StartFractalShots(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_SpikeGrenade.StartFractalShots" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShootFractalShot(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_SpikeGrenade.ShootFractalShot" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnFractalExplosionEffects( Vector ShotLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_SpikeGrenade.SpawnFractalExplosionEffects" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = ShotLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndFractal(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_SpikeGrenade.EndFractal" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnExplosionEffects( Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_SpikeGrenade.SpawnExplosionEffects" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = HitLocation;
				*( Vector* )( params + 12 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
