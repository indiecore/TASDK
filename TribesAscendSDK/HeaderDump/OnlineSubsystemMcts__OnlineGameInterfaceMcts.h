#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " OnlineSubsystemMcts.OnlineGameInterfaceMcts." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty OnlineSubsystemMcts.OnlineGameInterfaceMcts." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty OnlineSubsystemMcts.OnlineGameInterfaceMcts." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineGameInterfaceMcts : public OnlineGameInterfaceImpl
	{
	public:
			ADD_OBJECT( OnlineGameSearch, InviteGameSearch )
			ADD_OBJECT( OnlineVoiceInterfaceMcts, MctsVoiceInt )
			ADD_OBJECT( MctsOnlineSettings, MctsSettings )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
