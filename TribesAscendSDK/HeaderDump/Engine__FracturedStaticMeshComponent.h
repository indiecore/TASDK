#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.FracturedStaticMeshComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.FracturedStaticMeshComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.FracturedStaticMeshComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FracturedStaticMeshComponent : public FracturedBaseComponent
	{
	public:
			ADD_VAR( ::FloatProperty, FragmentBoundsMinZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FragmentBoundsMaxZ, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInterface, LoseChunkOutsideMaterialOverride )
			ADD_VAR( ::FloatProperty, TopBottomFragmentDistThreshold, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bBottomFragmentsRootNonDestroyable, 0x8 )
			ADD_VAR( ::BoolProperty, bTopFragmentsRootNonDestroyable, 0x4 )
			ADD_VAR( ::BoolProperty, bUseVisibleVertsForBounds, 0x2 )
			ADD_VAR( ::BoolProperty, bUseSkinnedRendering, 0x1 )
			void SetVisibleFragments(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshComponent.SetVisibleFragments" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsFragmentDestroyable( int FragmentIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshComponent.IsFragmentDestroyable" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = FragmentIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsRootFragment( int FragmentIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshComponent.IsRootFragment" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = FragmentIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsNoPhysFragment( int FragmentIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshComponent.IsNoPhysFragment" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = FragmentIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void* GetFragmentBox( int FragmentIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshComponent.GetFragmentBox" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = FragmentIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			Vector GetFragmentAverageExteriorNormal( int FragmentIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshComponent.GetFragmentAverageExteriorNormal" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = FragmentIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			int GetCoreFragmentIndex(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshComponent.GetCoreFragmentIndex" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void* GetFragmentGroups( float MinConnectionArea )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshComponent.GetFragmentGroups" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 12 ) = MinConnectionArea;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* GetBoundaryHiddenFragments(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshComponent.GetBoundaryHiddenFragments" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void RecreatePhysState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshComponent.RecreatePhysState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class PhysicalMaterial* GetFracturedMeshPhysMaterial(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FracturedStaticMeshComponent.GetFracturedMeshPhysMaterial" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PhysicalMaterial** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
