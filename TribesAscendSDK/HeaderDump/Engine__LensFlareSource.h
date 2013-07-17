#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.LensFlareSource." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.LensFlareSource." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.LensFlareSource." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LensFlareSource : public Actor
	{
	public:
			ADD_VAR( ::BoolProperty, bCurrentlyActive, 0x1 )
			void SetTemplate( class LensFlare* NewTemplate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LensFlareSource.SetTemplate" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LensFlare** )( params + 0 ) = NewTemplate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LensFlareSource.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnToggle( class SeqAct_Toggle* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LensFlareSource.OnToggle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Toggle** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LensFlareSource.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFloatParameter( ScriptName ParameterName, float Param )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LensFlareSource.SetFloatParameter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( float* )( params + 8 ) = Param;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVectorParameter( ScriptName ParameterName, Vector Param )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LensFlareSource.SetVectorParameter" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( Vector* )( params + 8 ) = Param;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetColorParameter( ScriptName ParameterName, void* Param )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LensFlareSource.SetColorParameter" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( void** )( params + 8 ) = Param;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetExtColorParameter( ScriptName ParameterName, float Red, float Green, float Blue, float Alpha )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LensFlareSource.SetExtColorParameter" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( float* )( params + 8 ) = Red;
				*( float* )( params + 12 ) = Green;
				*( float* )( params + 16 ) = Blue;
				*( float* )( params + 20 ) = Alpha;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetActorParameter( ScriptName ParameterName, class Actor* Param )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LensFlareSource.SetActorParameter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( class Actor** )( params + 8 ) = Param;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
