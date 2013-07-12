#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.GFxTrPage_PartyInvite." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.GFxTrPage_PartyInvite." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.GFxTrPage_PartyInvite." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_PartyInvite : public GFxTrPage
	{
	public:
			ADD_VAR( ::StrProperty, MemberName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Action_InviteFailed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Action_SendMessage, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Action_InviteSent, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Action_ByName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PopupNum, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
