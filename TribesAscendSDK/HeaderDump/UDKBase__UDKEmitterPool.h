#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKEmitterPool." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKEmitterPool." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKEmitterPool." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKEmitterPool : public EmitterPool
	{
	public:
			void* SpawnEmitter( class ParticleSystem* EmitterTemplate, Vector SpawnLocation, Rotator SpawnRotation, class Actor* AttachToActor, bool bInheritScaleFromBase )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKEmitterPool.SpawnEmitter" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class ParticleSystem** )params = EmitterTemplate;
				*( Vector* )( params + 4 ) = SpawnLocation;
				*( Rotator* )( params + 16 ) = SpawnRotation;
				*( class Actor** )( params + 28 ) = AttachToActor;
				*( bool* )( params + 32 ) = bInheritScaleFromBase;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void OnExplosionLightFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKEmitterPool.OnExplosionLightFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* SpawnExplosionLight( ScriptClass* LightClass, Vector SpawnLocation, class Actor* AttachToActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKEmitterPool.SpawnExplosionLight" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptClass** )params = LightClass;
				*( Vector* )( params + 4 ) = SpawnLocation;
				*( class Actor** )( params + 16 ) = AttachToActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
