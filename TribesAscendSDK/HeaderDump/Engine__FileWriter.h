#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.FileWriter." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.FileWriter." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.FileWriter." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FileWriter : public Info
	{
	public:
			ADD_VAR( ::StrProperty, Filename, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, FileType, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bFlushEachWrite, 0x1 )
			ADD_VAR( ::BoolProperty, bWantsAsyncWrites, 0x2 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
