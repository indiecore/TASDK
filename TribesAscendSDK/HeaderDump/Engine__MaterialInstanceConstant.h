#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.MaterialInstanceConstant." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.MaterialInstanceConstant." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.MaterialInstanceConstant." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MaterialInstanceConstant : public MaterialInstance
	{
	public:
			void SetParent( class MaterialInterface* NewParent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceConstant.SetParent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class MaterialInterface** )params = NewParent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetScalarParameterValue( ScriptName ParameterName, float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceConstant.SetScalarParameterValue" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = ParameterName;
				*( float* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetTextureParameterValue( ScriptName ParameterName, class Texture* Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceConstant.SetTextureParameterValue" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = ParameterName;
				*( class Texture** )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVectorParameterValue( ScriptName ParameterName, void* &Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceConstant.SetVectorParameterValue" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )params = ParameterName;
				*( void** )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Value = *( void** )( params + 8 );
			}

			void SetFontParameterValue( ScriptName ParameterName, class Font* FontValue, int FontPage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceConstant.SetFontParameterValue" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )params = ParameterName;
				*( class Font** )( params + 8 ) = FontValue;
				*( int* )( params + 12 ) = FontPage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearParameterValues(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstanceConstant.ClearParameterValues" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
