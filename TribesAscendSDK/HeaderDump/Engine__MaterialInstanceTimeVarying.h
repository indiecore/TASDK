#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.MaterialInstanceTimeVarying." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.MaterialInstanceTimeVarying." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.MaterialInstanceTimeVarying." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MaterialInstanceTimeVarying : public MaterialInstance
	{
	public:
			ADD_VAR( ::FloatProperty, Duration, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAutoActivateAll, 0x1 )
			void SetParent( class MaterialInterface* NewParent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceTimeVarying.SetParent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class MaterialInterface** )( params + 0 ) = NewParent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetScalarParameterValue( ScriptName ParameterName, float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceTimeVarying.SetScalarParameterValue" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( float* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetScalarCurveParameterValue( ScriptName ParameterName, void* &Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceTimeVarying.SetScalarCurveParameterValue" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( void** )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Value = *( void** )( params + 8 );
			}

			void SetScalarStartTime( ScriptName ParameterName, float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceTimeVarying.SetScalarStartTime" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( float* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDuration( float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceTimeVarying.SetDuration" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetTextureParameterValue( ScriptName ParameterName, class Texture* Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceTimeVarying.SetTextureParameterValue" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( class Texture** )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVectorParameterValue( ScriptName ParameterName, void* &Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceTimeVarying.SetVectorParameterValue" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( void** )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Value = *( void** )( params + 8 );
			}

			void SetVectorCurveParameterValue( ScriptName ParameterName, void* &Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceTimeVarying.SetVectorCurveParameterValue" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( void** )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Value = *( void** )( params + 8 );
			}

			void SetVectorStartTime( ScriptName ParameterName, float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceTimeVarying.SetVectorStartTime" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( float* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFontParameterValue( ScriptName ParameterName, class Font* FontValue, int FontPage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceTimeVarying.SetFontParameterValue" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( class Font** )( params + 8 ) = FontValue;
				*( int* )( params + 12 ) = FontPage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearParameterValues(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceTimeVarying.ClearParameterValues" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetMaxDurationFromAllParameters(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceTimeVarying.GetMaxDurationFromAllParameters" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
