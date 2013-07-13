#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PBRuleNodeWindowWall." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PBRuleNodeWindowWall." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PBRuleNodeWindowWall." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PBRuleNodeWindowWall : public PBRuleNodeBase
	{
	public:
			ADD_OBJECT( MaterialInterface, Material )
			ADD_VAR( ::FloatProperty, YOffset, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bScaleWindowWithCell, 0x1 )
			ADD_VAR( ::FloatProperty, WindowPosZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WindowPosX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WindowSizeZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WindowSizeX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CellMaxSizeZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CellMaxSizeX, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
