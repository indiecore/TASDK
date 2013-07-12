#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.OnlinePlayerStorage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.OnlinePlayerStorage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.OnlinePlayerStorage." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlinePlayerStorage : public Object
	{
	public:
			ADD_VAR( ::IntProperty, DeviceID, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, AsyncState, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, VersionNumber, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, VersionSettingsId, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
