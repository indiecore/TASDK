#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PBRuleNodeQuad." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PBRuleNodeQuad." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PBRuleNodeQuad." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PBRuleNodeQuad : public PBRuleNodeBase
	{
	public:
			ADD_VAR( ::BoolProperty, bDisableMaterialRepeat, 0x1 )
			ADD_VAR( ::FloatProperty, YOffset, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, QuadLightmapRes, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RepeatMaxSizeZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RepeatMaxSizeX, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInterface, Material )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
