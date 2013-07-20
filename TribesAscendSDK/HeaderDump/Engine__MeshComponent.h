#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.MeshComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.MeshComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.MeshComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MeshComponent : public PrimitiveComponent
	{
	public:
			class MaterialInterface* GetMaterial( int ElementIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MeshComponent.GetMaterial" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ElementIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class MaterialInterface** )( params + function->return_val_offset() );
			}

			void SetMaterial( int ElementIndex, class MaterialInterface* Material )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MeshComponent.SetMaterial" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ElementIndex;
				*( class MaterialInterface** )( params + 4 ) = Material;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetNumElements(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MeshComponent.GetNumElements" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void PrestreamTextures( float Seconds, bool bPrioritizeCharacterTextures, int CinematicTextureGroups )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MeshComponent.PrestreamTextures" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )params = Seconds;
				*( bool* )( params + 4 ) = bPrioritizeCharacterTextures;
				*( int* )( params + 8 ) = CinematicTextureGroups;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class MaterialInstanceConstant* CreateAndSetMaterialInstanceConstant( int ElementIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MeshComponent.CreateAndSetMaterialInstanceConstant" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ElementIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class MaterialInstanceConstant** )( params + function->return_val_offset() );
			}

			class MaterialInstanceTimeVarying* CreateAndSetMaterialInstanceTimeVarying( int ElementIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MeshComponent.CreateAndSetMaterialInstanceTimeVarying" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ElementIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class MaterialInstanceTimeVarying** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
