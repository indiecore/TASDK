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
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
