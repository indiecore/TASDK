#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.DrawBoxComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.DrawBoxComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.DrawBoxComponent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DrawBoxComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::BoolProperty, bDrawOnlyIfSelected, 0x4 )
			ADD_VAR( ::BoolProperty, bDrawLitBox, 0x2 )
			ADD_VAR( ::BoolProperty, bDrawWireBox, 0x1 )
			ADD_STRUCT( ::VectorProperty, BoxExtent, 0xFFFFFFFF )
			ADD_OBJECT( Material, BoxMaterial )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
