#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PlayerStart." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PlayerStart." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PlayerStart." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PlayerStart : public NavigationPoint
	{
	public:
			ADD_VAR( ::BoolProperty, bEnabled, 0x1 )
			ADD_VAR( ::BoolProperty, bPrimaryStart, 0x2 )
			ADD_VAR( ::IntProperty, TeamIndex, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
