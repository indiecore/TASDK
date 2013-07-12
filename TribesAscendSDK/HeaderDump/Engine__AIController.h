#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.AIController." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.AIController." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.AIController." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AIController : public Controller
	{
	public:
			ADD_OBJECT( Actor, ScriptedFocus )
			ADD_VAR( ::IntProperty, ScriptedRouteIndex, 0xFFFFFFFF )
			ADD_OBJECT( Route, ScriptedRoute )
			ADD_OBJECT( Actor, ScriptedMoveTarget )
			ADD_VAR( ::FloatProperty, Skill, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bReverseScriptedRoute, 0x2 )
			ADD_VAR( ::BoolProperty, bAdjustFromWalls, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
