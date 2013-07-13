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
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
