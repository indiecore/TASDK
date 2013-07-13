#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.InternetLink." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.InternetLink." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.InternetLink." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class InternetLink : public Info
	{
	public:
			ADD_VAR( ::IntProperty, DataPending, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Port, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ReceiveMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, OutLineMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LinkMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, InLineMode, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
