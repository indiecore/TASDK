#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.StaticMeshComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.StaticMeshComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.StaticMeshComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class StaticMeshComponent : public MeshComponent
	{
	public:
			bool CanBecomeDynamic(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.StaticMeshComponent.CanBecomeDynamic" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, VertexPositionVersionNumber, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bNeverBecomeDynamic, 0x1 )
			ADD_VAR( ::ByteProperty, SimpleLightmapModificationFunction, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ForcedLodModel, 0xFFFFFFFF )
			ADD_OBJECT( Texture, SimpleLightmapModificationTexture )
			ADD_VAR( ::BoolProperty, bUseSimpleLightmapModifications, 0x8 )
			ADD_VAR( ::BoolProperty, bCanHighlightSelectedSections, 0x4 )
			ADD_VAR( ::BoolProperty, bForceStaticDecals, 0x2 )
			ADD_VAR( ::BoolProperty, bUseSubDivisions, 0x1 )
			ADD_VAR( ::IntProperty, SubDivisionStepSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OverriddenLODMaxRange, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, OverriddenLightMapRes, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, OverriddenLightMapResolution, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bOverrideLightMapRes, 0x4 )
			ADD_VAR( ::BoolProperty, bOverrideLightMapResolution, 0x2 )
			ADD_VAR( ::BoolProperty, bIgnoreInstanceForTextureStreaming, 0x1 )
			ADD_OBJECT( StaticMesh, StaticMesh )
			ADD_VAR( ::IntProperty, PreviousLODLevel, 0xFFFFFFFF )
			bool SetStaticMesh( class StaticMesh* NewMesh, bool bForce )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.StaticMeshComponent.SetStaticMesh" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class StaticMesh** )( params + 0 ) = NewMesh;
				*( bool* )( params + 4 ) = bForce;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DisableRBCollisionWithSMC( bool bDisabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.StaticMeshComponent.DisableRBCollisionWithSMC" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 4 ) = bDisabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetForceStaticDecals( bool bInForceStaticDecals )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.StaticMeshComponent.SetForceStaticDecals" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bInForceStaticDecals;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
