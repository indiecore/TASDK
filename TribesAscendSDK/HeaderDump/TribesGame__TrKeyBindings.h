#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrKeyBindings." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrKeyBindings." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrKeyBindings." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrKeyBindings : public GFxObject
	{
	public:
			ADD_VAR( ::StrProperty, m_EscapeKeybind, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_FriendsHotkey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_SettingsHotkey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_MainMenuHotkey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_ClassSelectKeybind, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TeamSelectKeybind, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TalkReplyKeybind, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_ChatHotkey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TalkKeybind, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TeamTalkKeybind, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_ScoreboardKeybind, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_EnterKeybind, 0xFFFFFFFF )
			ADD_OBJECT( PlayerInput, m_EngineInput )
			ADD_OBJECT( GFxObject, m_KeyBindingsList )
			ADD_VAR( ::IntProperty, m_KeyBindingsCount, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bGotInputKey, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
