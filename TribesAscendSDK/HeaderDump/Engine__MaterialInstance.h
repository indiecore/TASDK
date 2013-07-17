#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.MaterialInstance." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.MaterialInstance." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.MaterialInstance." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MaterialInstance : public MaterialInterface
	{
	public:
			ADD_VAR( ::BoolProperty, bNeedsMaterialFlattening, 0x8 )
			ADD_VAR( ::BoolProperty, ReentrantFlag, 0x4 )
			ADD_VAR( ::BoolProperty, bStaticPermutationDirty, 0x2 )
			ADD_VAR( ::BoolProperty, bHasStaticPermutationResource, 0x1 )
			ADD_OBJECT( PhysicalMaterial, WhitePhysicalMaterial )
			ADD_OBJECT( PhysicalMaterial, BlackPhysicalMaterial )
			ADD_VAR( ::IntProperty, PhysMaterialMaskUVChannel, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, PhysMaterialMask )
			ADD_OBJECT( MaterialInterface, Parent )
			ADD_OBJECT( PhysicalMaterial, PhysMaterial )
			void SetParent( class MaterialInterface* NewParent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstance.SetParent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class MaterialInterface** )( params + 0 ) = NewParent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVectorParameterValue( ScriptName ParameterName, void* &Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstance.SetVectorParameterValue" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( void** )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Value = *( void** )( params + 8 );
			}

			void SetScalarParameterValue( ScriptName ParameterName, float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstance.SetScalarParameterValue" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( float* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetScalarCurveParameterValue( ScriptName ParameterName, void* &Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstance.SetScalarCurveParameterValue" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( void** )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Value = *( void** )( params + 8 );
			}

			void SetTextureParameterValue( ScriptName ParameterName, class Texture* Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstance.SetTextureParameterValue" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( class Texture** )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFontParameterValue( ScriptName ParameterName, class Font* FontValue, int FontPage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstance.SetFontParameterValue" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( class Font** )( params + 8 ) = FontValue;
				*( int* )( params + 12 ) = FontPage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearParameterValues(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstance.ClearParameterValues" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsInMapOrTransientPackage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MaterialInstance.IsInMapOrTransientPackage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
