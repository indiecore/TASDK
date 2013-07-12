#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.CheatManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.CheatManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.CheatManager." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class CheatManager : public Object
	{
	public:
			ADD_VAR( ::StrProperty, OwnCamera, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ViewingFrom, 0xFFFFFFFF )
			ADD_OBJECT( DebugCameraController, DebugCameraControllerRef )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
