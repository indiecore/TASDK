#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " IpDrv.OnlineSubsystemCommonImpl." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty IpDrv.OnlineSubsystemCommonImpl." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty IpDrv.OnlineSubsystemCommonImpl." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineSubsystemCommonImpl : public OnlineSubsystem
	{
	public:
			ADD_OBJECT( OnlineGameInterfaceImpl, GameInterfaceImpl )
			ADD_VAR( ::BoolProperty, bIsUsingSpeechRecognition, 0x1 )
			ADD_VAR( ::IntProperty, MaxRemoteTalkers, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxLocalTalkers, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
