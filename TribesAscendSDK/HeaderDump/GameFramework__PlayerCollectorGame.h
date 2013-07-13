#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.PlayerCollectorGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.PlayerCollectorGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.PlayerCollectorGame." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PlayerCollectorGame : public GameInfo
	{
	public:
			ADD_VAR( ::StrProperty, URLToLoad, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumberOfClientsToWaitFor, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
