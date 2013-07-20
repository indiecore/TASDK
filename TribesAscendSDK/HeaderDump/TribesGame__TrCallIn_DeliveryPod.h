#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrCallIn_DeliveryPod." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrCallIn_DeliveryPod." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrCallIn_DeliveryPod." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCallIn_DeliveryPod : public Actor
	{
	public:
			ADD_VAR( ::FloatProperty, Speed, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, TargetImpactPoint, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, TargetHitNormal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LifeAfterImpact, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, ImpactSound )
			ADD_OBJECT( SoundCue, FallingSound )
			ADD_OBJECT( ParticleSystem, DeliveryPodImpactTemplate )
			ADD_OBJECT( ParticleSystem, DeliveryPodParticleTemplate )
			ADD_VAR( ::FloatProperty, DecalDissolveTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HitDecalWidth, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HitDecalHeight, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceTimeVarying, PodHitDecal )
			float GetTerminalVelocity(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_DeliveryPod.GetTerminalVelocity" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void Init( class TrCallIn_CrashLandInfo* CrashInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_DeliveryPod.Init" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrCallIn_CrashLandInfo** )params = CrashInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BreakApart(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_DeliveryPod.BreakApart" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HideMesh(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_DeliveryPod.HideMesh" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ParticleSystemFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_DeliveryPod.ParticleSystemFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_DeliveryPod.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_DeliveryPod.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
