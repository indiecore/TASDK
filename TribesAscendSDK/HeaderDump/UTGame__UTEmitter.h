#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTEmitter." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTEmitter." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTEmitter." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTEmitter : public Emitter
	{
	public:
			class ParticleSystem* GetTemplateForDistance( Vector SpawnLocation, class WorldInfo* WI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEmitter.GetTemplateForDistance" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )( params + 12 ) = SpawnLocation;
				*( class WorldInfo** )( params + 24 ) = WI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class ParticleSystem** )( params + function->return_val_offset() );
			}

			void SetTemplate( class ParticleSystem* NewTemplate, bool bDestroyOnFinish )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEmitter.SetTemplate" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class ParticleSystem** )params = NewTemplate;
				*( bool* )( params + 4 ) = bDestroyOnFinish;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLightEnvironment(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEmitter.SetLightEnvironment" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
