#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrStreamManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrStreamManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrStreamManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrStreamManager : public Object
	{
	public:
			ADD_VAR( ::StrProperty, StreamServer, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, StreamPath, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, StreamURL, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, WatchEnd, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, WatchStart, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TokViewers, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TokTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TokName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NewsIndex, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUpdateReady, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
