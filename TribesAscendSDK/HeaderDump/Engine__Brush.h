#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Brush." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Brush." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Brush." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Brush : public Actor
	{
	public:
			ADD_OBJECT( Model, Brush )
			ADD_VAR( ::BoolProperty, bPlaceableFromClassBrowser, 0x4 )
			ADD_VAR( ::BoolProperty, bSolidWhenSelected, 0x2 )
			ADD_VAR( ::BoolProperty, bColored, 0x1 )
			ADD_VAR( ::IntProperty, PolyFlags, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CsgOper, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
