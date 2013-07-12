#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrChatConsole." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrChatConsole." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrChatConsole." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrChatConsole : public UTConsole
	{
	public:
			ADD_OBJECT( TrPlayerController, m_TrPC )
			ADD_VAR( ::FloatProperty, m_fTypingTime, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EscHelp, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TabHelp, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TellHelp, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SlashHelp, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastFriendCount, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ChannelStr, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
