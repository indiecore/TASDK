#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SpeedTreeComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SpeedTreeComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SpeedTreeComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SpeedTreeComponent : public PrimitiveComponent
	{
	public:
			ADD_OBJECT( Texture2D, SpeedTreeIcon )
			ADD_OBJECT( MaterialInterface, BillboardMaterial )
			ADD_OBJECT( MaterialInterface, LeafMeshMaterial )
			ADD_OBJECT( MaterialInterface, LeafCardMaterial )
			ADD_OBJECT( MaterialInterface, FrondMaterial )
			ADD_OBJECT( MaterialInterface, Branch2Material )
			ADD_OBJECT( MaterialInterface, Branch1Material )
			ADD_VAR( ::FloatProperty, LodLevelOverride, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LodBillboardEnd, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LodBillboardStart, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Lod3DEnd, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Lod3DStart, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUseBillboards, 0x10 )
			ADD_VAR( ::BoolProperty, bUseFronds, 0x8 )
			ADD_VAR( ::BoolProperty, bUseBranches, 0x4 )
			ADD_VAR( ::BoolProperty, bUseLeafMeshes, 0x2 )
			ADD_VAR( ::BoolProperty, bUseLeafCards, 0x1 )
			ADD_OBJECT( SpeedTree, SpeedTree )
			class MaterialInterface* GetMaterial( byte MeshType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SpeedTreeComponent.GetMaterial" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = MeshType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class MaterialInterface** )( params + function->return_val_offset() );
			}

			void SetMaterial( byte MeshType, class MaterialInterface* Material )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SpeedTreeComponent.SetMaterial" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = MeshType;
				*( class MaterialInterface** )( params + 4 ) = Material;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
