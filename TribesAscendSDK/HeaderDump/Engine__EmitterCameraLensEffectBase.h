#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.EmitterCameraLensEffectBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.EmitterCameraLensEffectBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.EmitterCameraLensEffectBase." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class EmitterCameraLensEffectBase : public Emitter
	{
	public:
			ADD_VAR( ::BoolProperty, bAllowMultipleInstances, 0x1 )
			ADD_OBJECT( Camera, BaseCamera )
			ADD_VAR( ::FloatProperty, DistFromCamera, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BaseFOV, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, PS_CameraEffectNonExtremeContent )
			ADD_OBJECT( ParticleSystem, PS_CameraEffect )
			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterCameraLensEffectBase.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RegisterCamera( class Camera* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterCameraLensEffectBase.RegisterCamera" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Camera** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyRetriggered(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterCameraLensEffectBase.NotifyRetriggered" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterCameraLensEffectBase.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActivateLensEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterCameraLensEffectBase.ActivateLensEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateLocation( Vector &CamLoc, Rotator &CamRot, float CamFOVDeg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterCameraLensEffectBase.UpdateLocation" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )params = CamLoc;
				*( Rotator* )( params + 12 ) = CamRot;
				*( float* )( params + 24 ) = CamFOVDeg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				CamLoc = *( Vector* )params;
				CamRot = *( Rotator* )( params + 12 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
