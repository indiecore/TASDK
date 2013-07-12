#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.UIDataProvider_OnlineFriendMessages." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.UIDataProvider_OnlineFriendMessages." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.UIDataProvider_OnlineFriendMessages." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataProvider_OnlineFriendMessages : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
			ADD_VAR( ::StrProperty, LastInviteFrom, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, MessageCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, bWasDeniedCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, bWasAcceptedCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, bIsFriendInviteCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SendingPlayerNameCol, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
