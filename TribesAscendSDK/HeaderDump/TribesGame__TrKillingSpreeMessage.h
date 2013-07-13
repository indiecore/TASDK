#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrKillingSpreeMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrKillingSpreeMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrKillingSpreeMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrKillingSpreeMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, EndSpreeNoteTrailer, 0xFFFFFFFF )
			ADD_OBJECT( SoundNodeWave, SpreeSound )
			ADD_VAR( ::StrProperty, SelfSpreeNote, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SpreeNote, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, MultiKillString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EndSelfSpree, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EndSpreeNote, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
