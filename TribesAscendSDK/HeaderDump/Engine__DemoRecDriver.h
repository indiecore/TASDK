#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.DemoRecDriver." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.DemoRecDriver." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.DemoRecDriver." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DemoRecDriver : public NetDriver
	{
	public:
			ADD_VAR( ::StrProperty, DemoSpectatorClass, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxRewindPoints, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RewindPointInterval, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumRecentRewindPoints, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
