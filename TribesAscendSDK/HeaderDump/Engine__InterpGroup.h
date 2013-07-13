#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.InterpGroup." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.InterpGroup." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.InterpGroup." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class InterpGroup : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, bIsSelected, 0x10 )
			ADD_VAR( ::BoolProperty, bIsParented, 0x8 )
			ADD_VAR( ::BoolProperty, bIsFolder, 0x4 )
			ADD_VAR( ::BoolProperty, bVisible, 0x2 )
			ADD_VAR( ::BoolProperty, bCollapsed, 0x1 )
			ADD_VAR( ::NameProperty, GroupName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
