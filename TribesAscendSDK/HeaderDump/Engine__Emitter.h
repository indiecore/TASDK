#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Emitter." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Emitter." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Emitter." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Emitter : public Actor
	{
	public:
			ADD_VAR( ::BoolProperty, bCurrentlyActive, 0x4 )
			ADD_VAR( ::BoolProperty, bPostUpdateTickGroup, 0x2 )
			ADD_VAR( ::BoolProperty, bDestroyOnSystemFinish, 0x1 )
			void SetTemplate( class ParticleSystem* NewTemplate, bool bDestroyOnFinish )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.SetTemplate" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class ParticleSystem** )params = NewTemplate;
				*( bool* )( params + 4 ) = bDestroyOnFinish;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnParticleSystemFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.OnParticleSystemFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnToggle( class SeqAct_Toggle* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.OnToggle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Toggle** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnParticleEventGenerator( class SeqAct_ParticleEventGenerator* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.OnParticleEventGenerator" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ParticleEventGenerator** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.ShutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFloatParameter( ScriptName ParameterName, float Param )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.SetFloatParameter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = ParameterName;
				*( float* )( params + 8 ) = Param;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVectorParameter( ScriptName ParameterName, Vector Param )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.SetVectorParameter" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = ParameterName;
				*( Vector* )( params + 8 ) = Param;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetColorParameter( ScriptName ParameterName, void* Param )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.SetColorParameter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = ParameterName;
				*( void** )( params + 8 ) = Param;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetExtColorParameter( ScriptName ParameterName, byte Red, byte Green, byte Blue, byte Alpha )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.SetExtColorParameter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = ParameterName;
				*( byte* )( params + 8 ) = Red;
				*( byte* )( params + 9 ) = Green;
				*( byte* )( params + 10 ) = Blue;
				*( byte* )( params + 11 ) = Alpha;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetActorParameter( ScriptName ParameterName, class Actor* Param )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.SetActorParameter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = ParameterName;
				*( class Actor** )( params + 8 ) = Param;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSetParticleSysParam( class SeqAct_SetParticleSysParam* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.OnSetParticleSysParam" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetParticleSysParam** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldSaveForCheckpoint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.ShouldSaveForCheckpoint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CreateCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.CreateCheckpointRecord" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )params = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )params;
			}

			void ApplyCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.ApplyCheckpointRecord" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )params = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )params;
			}

			void HideSelf(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Emitter.HideSelf" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
