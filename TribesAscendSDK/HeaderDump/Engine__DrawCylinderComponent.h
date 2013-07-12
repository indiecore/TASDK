#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.DrawCylinderComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.DrawCylinderComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.DrawCylinderComponent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DrawCylinderComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::BoolProperty, bDrawOnlyIfSelected, 0x4 )
			ADD_VAR( ::BoolProperty, bDrawLitCylinder, 0x2 )
			ADD_VAR( ::BoolProperty, bDrawWireCylinder, 0x1 )
			ADD_VAR( ::IntProperty, CylinderSides, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CylinderHeightOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CylinderHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CylinderTopRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CylinderRadius, 0xFFFFFFFF )
			ADD_OBJECT( Material, CylinderMaterial )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
