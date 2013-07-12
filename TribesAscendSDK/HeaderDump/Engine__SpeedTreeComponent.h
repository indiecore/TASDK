#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SpeedTreeComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SpeedTreeComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SpeedTreeComponent." #y ) ); \
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
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
