#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ProcBuildingRuleset." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ProcBuildingRuleset." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ProcBuildingRuleset." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ProcBuildingRuleset : public Object
	{
	public:
			ADD_OBJECT( PBRuleNodeBase, RootRule )
			ADD_VAR( ::BoolProperty, bBeingEdited, 0x1 )
			ADD_VAR( ::BoolProperty, bEnableInteriorTexture, 0x2 )
			ADD_VAR( ::BoolProperty, bLODOnlyRoof, 0x4 )
			ADD_VAR( ::BoolProperty, bPickRandomSwatch, 0x8 )
			ADD_OBJECT( MaterialInterface, DefaultRoofMaterial )
			ADD_OBJECT( MaterialInterface, DefaultFloorMaterial )
			ADD_OBJECT( MaterialInterface, DefaultNonRectWallMaterial )
			ADD_VAR( ::FloatProperty, RoofZOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NotRoofZOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FloorZOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NotFloorZOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RoofPolyInset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FloorPolyInset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BuildingLODSpecular, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RoofEdgeScopeRaise, 0xFFFFFFFF )
			ADD_OBJECT( Texture, LODCubemap )
			ADD_OBJECT( Texture, InteriorTexture )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
