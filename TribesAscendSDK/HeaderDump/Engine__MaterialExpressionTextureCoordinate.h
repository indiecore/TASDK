#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.MaterialExpressionTextureCoordinate." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.MaterialExpressionTextureCoordinate." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.MaterialExpressionTextureCoordinate." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MaterialExpressionTextureCoordinate : public MaterialExpression
	{
	public:
			ADD_VAR( ::BoolProperty, UnMirrorV, 0x2 )
			ADD_VAR( ::BoolProperty, UnMirrorU, 0x1 )
			ADD_VAR( ::FloatProperty, VTiling, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UTiling, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CoordinateIndex, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
