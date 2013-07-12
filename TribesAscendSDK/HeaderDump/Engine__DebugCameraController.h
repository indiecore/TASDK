#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.DebugCameraController." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.DebugCameraController." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.DebugCameraController." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DebugCameraController : public PlayerController
	{
	public:
			ADD_OBJECT( Player, OryginalPlayer )
			ADD_OBJECT( PlayerController, OryginalControllerRef )
			ADD_OBJECT( Actor, SelectedActor )
			ADD_VAR( ::BoolProperty, bIsFrozenRendering, 0x2 )
			ADD_VAR( ::BoolProperty, bShowSelectedInfo, 0x1 )
			ADD_VAR( ::NameProperty, UnselectKey, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SecondaryKey, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, PrimaryKey, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
