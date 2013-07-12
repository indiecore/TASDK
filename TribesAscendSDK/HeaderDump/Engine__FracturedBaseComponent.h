#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.FracturedBaseComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.FracturedBaseComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.FracturedBaseComponent." #y ) ); \
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
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
