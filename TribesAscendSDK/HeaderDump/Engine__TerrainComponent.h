#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.TerrainComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.TerrainComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.TerrainComponent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TerrainComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::BoolProperty, bDisplayCollisionLevel, 0x1 )
			ADD_VAR( ::IntProperty, FullBatch, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TrueSectionSizeY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TrueSectionSizeX, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SectionSizeY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SectionSizeX, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SectionBaseY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SectionBaseX, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
