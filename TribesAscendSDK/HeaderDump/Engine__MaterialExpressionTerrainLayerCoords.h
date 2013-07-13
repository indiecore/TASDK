#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.MaterialExpressionTerrainLayerCoords." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.MaterialExpressionTerrainLayerCoords." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.MaterialExpressionTerrainLayerCoords." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MaterialExpressionTerrainLayerCoords : public MaterialExpression
	{
	public:
			ADD_VAR( ::FloatProperty, MappingPanV, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MappingPanU, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MappingRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MappingScale, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, MappingType, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
