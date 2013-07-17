#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.FracturedBaseComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.FracturedBaseComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.FracturedBaseComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FracturedBaseComponent : public StaticMeshComponent
	{
	public:
			ADD_VAR( ::IntProperty, bResetStaticMesh, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumResourceIndices, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUseDynamicIBWithHiddenFragments, 0x10 )
			ADD_VAR( ::BoolProperty, bUseDynamicIndexBuffer, 0x8 )
			ADD_VAR( ::BoolProperty, bInitialVisibilityValue, 0x4 )
			ADD_VAR( ::BoolProperty, bVisibilityReset, 0x2 )
			ADD_VAR( ::BoolProperty, bVisibilityHasChanged, 0x1 )
			bool SetStaticMesh( class StaticMesh* NewMesh, bool bForce )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedBaseComponent.SetStaticMesh" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class StaticMesh** )( params + 0 ) = NewMesh;
				*( bool* )( params + 4 ) = bForce;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void* GetVisibleFragments(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedBaseComponent.GetVisibleFragments" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			bool IsFragmentVisible( int FragmentIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedBaseComponent.IsFragmentVisible" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = FragmentIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetNumFragments(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedBaseComponent.GetNumFragments" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetNumVisibleFragments(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedBaseComponent.GetNumVisibleFragments" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
